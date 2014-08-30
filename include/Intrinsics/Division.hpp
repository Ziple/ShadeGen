#ifndef __SC_DIVISION_HPP__
#define __SC_DIVISION_HPP__

#include "BinaryOperator.hpp"

#include <Utils/SharablePointer.hpp>

class Division : public BinaryOperator, public Sharable<Division>
{
    
public:
    Division( Context* ctx, Operator* first, Operator* second );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );

    void ResolveTypes();
};

#endif // __SC_DIVISION_HPP__

