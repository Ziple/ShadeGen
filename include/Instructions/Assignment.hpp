#ifndef __ASSIGNMENT_HPP__
#define __ASSIGNMENT_HPP__

#include "Instruction.hpp"
#include <Utils/SharablePointer.hpp>

class Assignment : public Instruction, public Sharable<Assignment>
{
public:
    
    Assignment( Context* ctx, Variable* lval, Operator* rval );
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );
};

#endif /* __ASSIGNMENT_HPP__ */