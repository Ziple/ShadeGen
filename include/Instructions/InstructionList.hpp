#ifndef __INSTRUCTIONLIST_HPP__
#define __INSTRUCTIONLIST_HPP__

#include "Instruction.hpp"

#include <vector>

class InstructionList: public Instruction
{
public:
    
    InstructionList( Context* ctx, std::vector<Instruction*> ops  = std::vector<Instruction*>() );
    
    bool IsInstructionList() const;
    
    void PushBack( Instruction* op );
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
    Operator* Simplified( Context* nctx );
};

#endif /* __INSTRUCTIONLIST_HPP__ */