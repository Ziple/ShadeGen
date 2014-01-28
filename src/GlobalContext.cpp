#include <GlobalContext.hpp>
#include <Operator.hpp>
#include <Types/Type.hpp>
#include <Function.hpp>

#include <Types/ScalarTypes.hpp>
#include <Types/MatricialTypes.hpp>

GlobalContext::GlobalContext():
 Context(0),
 myMainFunction( 0 )
{
    new VoidType( this );
    new UnknownType( this );
    
    // scalar types
    new BoolType( this );
    new Uint32Type( this );
    new Int32Type( this );
    new HalfType( this );
    new FloatType( this );
    
    // matricial types
    new Vector2FloatType( this );
    new Vector3FloatType( this );
    new Vector4FloatType( this );
    new Matrix4x4FloatType( this );
    new Matrix3x4FloatType( this );
    new Matrix4x3FloatType( this );
    new Matrix3x3FloatType( this );
}

bool GlobalContext::IsTypeDeclared( Type* tp ) const
{
    return std::find( myDeclaredTypes.begin(), myDeclaredTypes.end(), tp ) != myDeclaredTypes.end();
}

void GlobalContext::RegisterType( Type* tp )
{
    bool canInsert = true;

    for( size_t i = 0; i < myRegisteredTypes.size(); i++ )
    {
        if( myRegisteredTypes[i]->GetName() == tp->GetName() )
        {
            canInsert = false;
            break;
        }
    }

    if( canInsert )
        myRegisteredTypes.push_back( tp );
}
        
void GlobalContext::UnregisterType( Type* tp )
{
    std::vector<Type*>::iterator pos = std::find( myRegisteredTypes.begin(), myRegisteredTypes.end(), tp );
    if( pos != myRegisteredTypes.end() )
        myRegisteredTypes.erase( pos );
}

void GlobalContext::DeclareType( Type* tp )
{
    if( std::find( myDeclaredTypes.begin(), myDeclaredTypes.end(), tp ) == myDeclaredTypes.end() )
        myDeclaredTypes.push_back( tp );
}

void GlobalContext::UndeclareType( Type* tp )
{
    std::vector<Type*>::iterator pos = std::find( myDeclaredTypes.begin(), myDeclaredTypes.end(), tp );
    if( pos != myDeclaredTypes.end() )
        myDeclaredTypes.erase( pos );
}
        
void GlobalContext::RegisterFunction( Function* fn )
{
    RegisterVariableName( fn->GetName() );
    if( std::find( myRegisteredFunctions.begin(), myRegisteredFunctions.end(), fn ) == myRegisteredFunctions.end() )
        myRegisteredFunctions.push_back( fn );
}

void GlobalContext::UnregisterFunction( Function* fn )
{
    std::vector<Function*>::iterator pos = std::find( myRegisteredFunctions.begin(), myRegisteredFunctions.end(), fn );
    if( pos != myRegisteredFunctions.end() )
        myRegisteredFunctions.erase( pos );
}

void GlobalContext::SetMainFunction( Function* m )
{
    myMainFunction = m;
}

void GlobalContext::CopyTypesToContext(
    GlobalContext* nctx,
    Operator::TypeCorrespondanceTable& correspondanceTable ) const
{
    for( size_t i = 0; i < myRegisteredTypes.size(); i++ )
    {
        Type* ntp = myRegisteredTypes[i]->Clone( nctx );
        correspondanceTable[ myRegisteredTypes[i] ] = ntp;

        if( IsTypeDeclared( myRegisteredTypes[i] ) )
            nctx->DeclareType( ntp );
    }
}

GlobalContext* GlobalContext::Simplify() const
{
    GlobalContext* ret = new GlobalContext();
    Operator::TypeCorrespondanceTable correspondanceTable;

    CopyTypesToContext( ret, correspondanceTable );

    if( myMainFunction != 0 )
        myMainFunction->Simplified(ret, correspondanceTable);
    else
        for( size_t i = 0; i < myRegisteredFunctions.size(); i++ )
            myRegisteredFunctions[i]->Simplified( ret, correspondanceTable );

    return ret;
}

void GlobalContext::ResolveTypes()
{
    for( size_t i = 0; i < myRegisteredFunctions.size(); i++ )
            myRegisteredFunctions[i]->ResolveTypes();
}

std::string GlobalContext::ToString()
{
    std::string ret;
    
    PrintingContext pctx;
    
    for( size_t i = 0; i < myDeclaredTypes.size(); i++ )
        ret += myDeclaredTypes[i]->DeclarationString( pctx ) + "\n";
    
    if( myMainFunction != 0 )
        ret += myMainFunction->ToString( pctx );
    else
    {
        for( size_t i = 0; i < myRegisteredFunctions.size(); i++ )
            ret += myRegisteredFunctions[i]->ToString( pctx ) + "\n";
    }
    
    return ret;
}