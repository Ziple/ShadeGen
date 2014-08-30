#ifndef __SC_GLOBALCONTEXT_HPP__
#define __SC_GLOBALCONTEXT_HPP__

#include "Context.hpp"
#include "Operator.hpp"

#include <Utils/SharablePointer.hpp>

#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Operator;
class Type;
class Function;

class GlobalContext : public Context, public Sharable<GlobalContext>
{
    public:
        
        GlobalContext();

        Context* GetGlobalContext() { return this; }

        bool IsTypeDeclared( Type* tp ) const;
        
        void RegisterType( Type* tp );
        
        void UnregisterType( Type* tp );
        
        void DeclareType( Type* tp );
        
        void UndeclareType( Type* tp );
        
        void RegisterFunction( Function* fn );
        
        void UnregisterFunction( Function* fn );
        
        void SetMainFunction( Function* m );

        void CopyTypesToContext(
            GlobalContext* nctx,
            Operator::TypeCorrespondanceTable& correspondanceTable ) const;
        
        GlobalContext* Simplify() const;

        void ResolveTypes();
        
        std::string ToString();
        
    protected:
        
        std::vector<Type*> myDeclaredTypes;
        std::vector<Function*> myRegisteredFunctions;
        Function* myMainFunction;
};

#endif // __SC_GLOBALCONTEXT_HPP__
