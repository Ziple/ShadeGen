#ifndef __SC_POWER_HPP__
#define __SC_POWER_HPP__

#include "BinaryOperator.hpp"

class Power: public BinaryOperator
{
public:
    Power( Context* ctx, Operator* first, Operator* second );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
    
    Operator* Simplified( Context* nctx );
};

#endif // __SC_POWER_HPP__
