#ifndef __SC_VARIABLE_HPP__
#define __SC_VARIABLE_HPP__

#include "Operator.hpp"

#include <string>

class Variable: public Operator
{
public:
    
    Variable( Context* ctx, const std::string& name );
    
    bool IsVariable() const;
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
protected:
    
    std::string myName;
};

#endif /* __SC_VARIABLE_HPP__ */

