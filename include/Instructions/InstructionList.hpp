#ifndef __INSTRUCTIONLIST_HPP__
#define __INSTRUCTIONLIST_HPP__

#include "Instruction.hpp"

#include <Utils/SharablePointer.hpp>

#include <vector>

class Return;

class InstructionList : public Instruction, public Sharable<InstructionList>
{
public:

    InstructionList( Context* ctx, Instruction* ins );
    
    InstructionList( Context* ctx, std::vector<Instruction*> ops  = std::vector<Instruction*>() );
    
    bool IsInstructionList() const;
    
    void PushBack( Instruction* op );
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );

    const std::vector<Return*> GetReturnInstructions() const { return myReturnInstructions; }

protected:

    void BuildReturnInstructionCache();

    std::vector<Return*> myReturnInstructions;
};

#endif /* __INSTRUCTIONLIST_HPP__ */