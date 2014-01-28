#ifndef __SC_DIVISION_HPP__
#define __SC_DIVISION_HPP__

#include "BinaryOperator.hpp"

class Division: public BinaryOperator
{
    
public:
    Division( Context* ctx, Operator* first, Operator* second );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );

    void ResolveTypes();
};

#endif // __SC_DIVISION_HPP__

