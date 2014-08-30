#ifndef __SC_MULTIPLICATION_HPP__
#define __SC_MULTIPLICATION_HPP__

#include "BinaryOperator.hpp"

#include <Utils/SharablePointer.hpp>

class GlobalContext;

class Multiplication : public BinaryOperator, public Sharable<Multiplication>
{
public:
    Multiplication( Context* ctx, Operator* first, Operator* second );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& table );

    void ResolveTypes();
};

#endif // __SC_MULTIPLICATION_HPP__
