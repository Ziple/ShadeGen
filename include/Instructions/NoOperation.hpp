#ifndef __NOOPERATION_HPP__
#define __NOOPERATION_HPP__

#include "Instruction.hpp"

class NoOperation: public Instruction
{
public:
    
    NoOperation( Context* ctx): Instruction(ctx) {}
    
    bool IsNoOp() const {return true;}
};

#endif /* __NOOPERATION_HPP__ */