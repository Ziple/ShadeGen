#ifndef __SC_POWER_HPP__
#define __SC_POWER_HPP__

#include "BinaryOperator.hpp"

#include <Utils/SharablePointer.hpp>

class Power : public BinaryOperator, public Sharable<Power>
{
public:
    Power( Context* ctx, Operator* first, Operator* second );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );

    void ResolveTypes();
};

#endif // __SC_POWER_HPP__
