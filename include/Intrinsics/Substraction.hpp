#ifndef __SC_SUBSTRACTION_HPP__
#define __SC_SUBSTRACTION_HPP__

#include "BinaryOperator.hpp"

class Substraction: public BinaryOperator
{
public:
    Substraction( Context* ctx, Operator* first, Operator* second );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
    
    Operator* Simplified( Context* nctx );
};

#endif // __SC_SUBSTRACTION_HPP__
