#ifndef __SC_CONTEXT_HPP__
#define __SC_CONTEXT_HPP__

#include <string>
#include <vector>
#include <algorithm>

class Operator;
class Function;
class Type;

class Context
{
    public:
        
        Context( Context* parent = 0 );
        
        virtual ~Context();

        virtual Context* GetGlobalContext() { return myParent != 0 ? myParent->GetGlobalContext() : 0; }
        
        Type* GetTypeByName( const std::string& name );

        virtual void RegisterFunction( Function* fn );
        
        virtual void UnregisterFunction( Function* fn );
        
        void RegisterOperator( Operator* op );
        
        void UnregisterOperator( Operator* op );
        
        void RegisterVariableName( const std::string& name );
        
        std::string GetFreeVariableName();
        
        bool IsVariableNameFree( const std::string& name );
        
    protected:
        
        Context* myParent;
        std::vector<Type*> myRegisteredTypes;
        std::vector<Operator*> myRegisteredOperators;
        std::vector<std::string> myRegisteredVariableNames;
};

#endif // __SC_CONTEXT_HPP__