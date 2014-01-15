#ifndef __SC_ADDITION_HPP__
#define __SC_ADDITION_HPP__

#include "BinaryOperator.hpp"

class Addition: public BinaryOperator
{
public:
    
    Addition( Context* ctx, Operator* first, Operator* second );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
    
    Operator* Simplified( Context* nctx );
};

#endif // __SC_ADDITION_HPP__ 
