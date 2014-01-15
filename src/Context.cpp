#include <Context.hpp>
#include <Operator.hpp>

Context::Context( Context* parent ):
 myParent( parent )
{
}

Context::~Context()
{
    // the operator will be removed from the container
    // when its own destructor is called.
    while( !myRegisteredOperators.empty() )
        delete myRegisteredOperators[0];
}

void Context::RegisterFunction( Function* fn )
{
    if( myParent != 0 )
        myParent->RegisterFunction(fn);
}

void Context::UnregisterFunction( Function* fn )
{
    if( myParent != 0 )
        myParent->UnregisterFunction(fn);
}
        
void Context::RegisterOperator( Operator* op )
{
    if( std::find( myRegisteredOperators.begin(), myRegisteredOperators.end(), op ) == myRegisteredOperators.end() )
        myRegisteredOperators.push_back( op );
}

void Context::UnregisterOperator( Operator* op )
{
    std::vector<Operator*>::iterator pos = std::find( myRegisteredOperators.begin(), myRegisteredOperators.end(), op );
    if( pos != myRegisteredOperators.end() )
        myRegisteredOperators.erase( pos );
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