#ifndef __SC_SUBSTRACTION_HPP__
#define __SC_SUBSTRACTION_HPP__

#include "BinaryOperator.hpp"

#include <Utils/SharablePointer.hpp>

class Substraction : public BinaryOperator, public Sharable<Substraction>
{
public:
    Substraction( Context* ctx, Operator* first, Operator* second );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );
};

#endif // __SC_SUBSTRACTION_HPP__
