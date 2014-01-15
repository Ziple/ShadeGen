#ifndef __SC_CONSTANT_HPP__
#define __SC_CONSTANT_HPP__

#include "Operator.hpp"

#include <sstream>

class Constant: public Operator
{
public:
    
    Constant( Context* ctx, double val );
    
    bool IsConstant() const;
    
    bool IsNull() const;
    
    bool IsOne() const;
    
    double GetValue() const ;
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
protected:
    
    double myValue;
};

#endif // __SC_CONSTANT_HPP__
