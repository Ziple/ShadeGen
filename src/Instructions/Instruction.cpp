#include <Instructions/Instruction.hpp>

Instruction::Instruction(
    Context* ctx,
    const std::vector<Operator*> ops ):
 Operator( ctx, ops )
{}
 
bool Instruction::IsInstruction() const { return true; }

bool Instruction::IsInstructionList() const { return false; }