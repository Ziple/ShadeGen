#ifndef __SC_OPERATOR_HPP__
#define __SC_OPERATOR_HPP__

#include <string>
#include <vector>

#include "PrintingContext.hpp"

class Context;
class Variable;

class Operator
{
    public:
        
        Operator( Context* ctx, const std::vector<Operator*> subops = std::vector<Operator*>() );
        
        virtual ~Operator();
        
        virtual Operator* Simplified( Context* nctx ) {}
        
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
};

#endif // __SC_OPERATOR_HPP__

