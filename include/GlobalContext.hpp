#ifndef __SC_GLOBALCONTEXT_HPP__
#define __SC_GLOBALCONTEXT_HPP__

#include "Context.hpp"

#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Operator;
class Type;
class Function;

class GlobalContext: public Context
{
    public:
        
        GlobalContext();
        
        void RegisterType( Type* tp );
        
        void UnregisterType( Type* tp );
        
        Type* GetTypeByName( const std::string& name );
        
        void DeclareType( Type* tp );
        
        void UndeclareType( Type* tp );
        
        void RegisterFunction( Function* fn );
        
        void UnregisterFunction( Function* fn );
        
        void SetMainFunction( Function* m );
        
        GlobalContext* Simplify();
        
        std::string ToString();
        
    protected:
        
        std::vector<Type*> myRegisteredTypes;
        std::vector<Type*> myDeclaredTypes;
        std::vector<Function*> myRegisteredFunctions;
        Function* myMainFunction;
};

#endif // __SC_GLOBALCONTEXT_HPP__
