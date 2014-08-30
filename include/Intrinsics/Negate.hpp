#ifndef __SC_NEGATE_HPP__
#define __SC_NEGATE_HPP__

#include "UnaryOperator.hpp"

#include <Utils/SharablePointer.hpp>

class Negate : public UnaryOperator, public Sharable<Negate>
{
public:
    Negate( Context* ctx, Operator* op );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );
};

#endif // __SC_NEGATE_HPP__
