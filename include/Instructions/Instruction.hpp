#ifndef __INSTRUCTION_HPP__
#define __INSTRUCTION_HPP__

#include <Operator.hpp>

class Instruction: public Operator
{
    public:
        
        Instruction( Context* ctx, const std::vector<Operator*> subops = std::vector<Operator*>() );
        
        virtual ~Instruction() {}
        
        virtual bool IsInstruction() const;
        
        virtual bool IsInstructionList() const;
};

#endif /* __INSTRUCTION_HPP__ */