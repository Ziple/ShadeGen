#include <Context.hpp>
#include <Operator.hpp>
#include <Types/Type.hpp>

Context::Context( Context::Ptr parent ):
 myParent( parent )
{
}

Context::~Context()
{}

Type::Ptr Context::GetTypeByName( const std::string& name )
{
    Type::Ptr ret = 0;
    
    for( size_t i = 0; i < myRegisteredTypes.size(); i++ )
        if( myRegisteredTypes[i]->GetName() == name )
        {
            ret = myRegisteredTypes[i];
            break;
        }

    if( ret == 0
        && myParent != 0 )
        ret = myParent->GetTypeByName( name );
        
    return ret;
}

void Context::RegisterFunction( Function::Ptr fn )
{
    if( myParent != 0 )
        myParent->RegisterFunction(fn);
}

void Context::UnregisterFunction( Function::Ptr fn )
{
    if( myParent != 0 )
        myParent->UnregisterFunction(fn);
}

void Context::RegisterVariableName( const std::string& name )
{
    myRegisteredVariableNames.push_back( name );
}

std::string Context::GetFreeVariableName()
{
    for( unsigned i = 1;; i++ )//nombre de lettres dans la variable
    {
        std::string t = "";
        // initialisation à a...a
        for( unsigned j = 0; j < i; j++ )
            t += "a";
        
        for( unsigned j = i-1; j >= 0; j-- )
        {
            for( unsigned k = j; k < i; k++ )
            {
                for( char l = 'u'; l <= 'z'; l++ )
                {
                    t[k] = l;
                    
                    if( IsVariableNameFree(t) )
                        return t;
                }
            }
        }
    }
}

bool Context::IsVariableNameFree( const std::string& name )
{
    bool freeForParent = true;
    if( myParent != 0 )
        freeForParent = myParent->IsVariableNameFree( name );
    
    return freeForParent && std::find( myRegisteredVariableNames.begin(), myRegisteredVariableNames.end(), name )
                        == myRegisteredVariableNames.end();
}