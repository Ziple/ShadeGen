#ifndef __SC_OPERATOR_HPP__
#define __SC_OPERATOR_HPP__

#include <string>
#include <vector>
#include <map>

#include "PrintingContext.hpp"

class Context;
class Variable;
class Type;

class Operator
{
    public:
        
        typedef std::map< Type* , Type* > TypeCorrespondanceTable;

        Operator(
            Context* ctx,
            const std::vector<Operator*> subops = std::vector<Operator*>(),
            Type* type = 0 );
        
        virtual ~Operator();

        virtual Operator* Simplified(
            Context* nctx,
            TypeCorrespondanceTable& correspondanceTable ) = 0;

        virtual void ResolveTypes() {}

        Type* GetType() const { return myType; }
        
        std::vector<const Variable*> GetVariables() const;
        
        virtual bool IsInstruction() const;
        
        virtual bool IsNoOp() const;
        
        virtual bool IsVariable() const;
        
        virtual bool IsConstant() const;
    
        virtual bool IsNull() const;
        
        virtual bool IsOne() const;
        
        virtual std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
        
    protected:
        
        Context* myContext;
        std::vector<Operator*> mySubOps;
        Type* myType;
};

#endif // __SC_OPERATOR_HPP__

