#ifndef __SC_OPERATOR_HPP__
#define __SC_OPERATOR_HPP__

#include <string>
#include <vector>
#include <map>

#include "Context.hpp"
#include "Variable.hpp"
#include "Types/Type.hpp"

#include "PrintingContext.hpp"

#include <Utils/SharablePointer.hpp>


class Context;
class Variable;
class Type;

class Operator : public Sharable<Operator>
{
    public:
        
        typedef std::map< Type::Ptr , Type::Ptr > TypeCorrespondanceTable;

        Operator(
            const std::vector<Operator::Ptr> subops = std::vector<Operator::Ptr>(),
            Type::Ptr type = 0 );
        
        virtual ~Operator();

        virtual Operator::Ptr Simplified( TypeCorrespondanceTable& correspondanceTable ) = 0;

        virtual void ResolveTypes() {}

        Type::Ptr GetType() const { return myType; }
        
        std::vector<Variable::Ptr> GetVariables() const;
        
        virtual bool IsInstruction() const;
        
        virtual bool IsNoOp() const;
        
        virtual bool IsVariable() const;
        
        virtual bool IsConstant() const;
    
        virtual bool IsNull() const;
        
        virtual bool IsOne() const;
        
        virtual std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
        
    protected:
        
        Context::Ptr myContext;
        std::vector<Operator::Ptr> mySubOps;
        Type::Ptr myType;
};

#endif // __SC_OPERATOR_HPP__

