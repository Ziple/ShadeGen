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

void GlobalContext::RegisterType( Type* tp )
{
    if( std::find( myRegisteredTypes.begin(), myRegisteredTypes.end(), tp ) == myRegisteredTypes.end() )
        myRegisteredTypes.push_back( tp );
}
        
void GlobalContext::UnregisterType( Type* tp )
{
    std::vector<Type*>::iterator pos = std::find( myRegisteredTypes.begin(), myRegisteredTypes.end(), tp );
    if( pos != myRegisteredTypes.end() )
        myRegisteredTypes.erase( pos );
}

Type* GlobalContext::GetTypeByName( const std::string& name )
{
    Type* ret = 0;
    
    for( size_t i = 0; i < myRegisteredTypes.size(); i++ )
        if( myRegisteredTypes[i]->GetName() == name )
        {
            ret = myRegisteredTypes[i];
            break;
        }
        
    return ret;
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

GlobalContext* GlobalContext::Simplify()
{
    
    return this;
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