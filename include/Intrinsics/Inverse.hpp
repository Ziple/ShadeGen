#ifndef __SC_INVERSE_HPP__
#define __SC_INVERSE_HPP__

#include "UnaryOperator.hpp"

class Inverse: public UnaryOperator
{
public:
    
    Inverse( Context* ctx, Operator* op );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
        
    Operator* Simplified( Context* nctx );
};

#endif // __SC_INVERSE_HPP__
