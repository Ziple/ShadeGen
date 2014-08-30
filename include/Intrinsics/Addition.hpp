#ifndef __SC_ADDITION_HPP__
#define __SC_ADDITION_HPP__

#include "BinaryOperator.hpp"
#include <Utils/SharablePointer.hpp>

class Addition: public BinaryOperator, public Sharable<Addition>
{
public:
    
    Addition( Operator::Ptr first, Operator::Ptr second );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
    
    Operator::Ptr Simplified( TypeCorrespondanceTable& correspondanceTable );
};

#endif // __SC_ADDITION_HPP__ 
