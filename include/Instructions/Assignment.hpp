#ifndef __ASSIGNMENT_HPP__
#define __ASSIGNMENT_HPP__

#include "Instruction.hpp"

class Assignment: public Instruction
{
public:
    
    Assignment( Context* ctx, Variable* lval, Operator* rval );
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );
};

#endif /* __ASSIGNMENT_HPP__ */