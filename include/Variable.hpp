#ifndef __SC_VARIABLE_HPP__
#define __SC_VARIABLE_HPP__

#include "Operator.hpp"

#include <string>

class Type;

class Variable: public Operator
{
public:
    
    Variable(
        Context* ctx,
        const std::string& name,
        Type* type = 0 );

    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable )
    {
        return new Variable( nctx, myName, correspondanceTable[GetType()] );
    }
    
    bool IsVariable() const;
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
protected:
    
    std::string myName;
};

#endif /* __SC_VARIABLE_HPP__ */

