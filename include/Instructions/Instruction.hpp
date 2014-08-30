#ifndef __INSTRUCTION_HPP__
#define __INSTRUCTION_HPP__

#include <Operator.hpp>

#include <Utils/SharablePointer.hpp>

class Instruction : public Operator, public Sharable<Instruction>
{
    public:
        
        Instruction( Context* ctx, const std::vector<Operator*> subops = std::vector<Operator*>() );
        
        virtual ~Instruction() {}
        
        virtual bool IsInstruction() const;
        
        virtual bool IsInstructionList() const;

        virtual bool IsReturn() const { return false; }
};

#endif /* __INSTRUCTION_HPP__ */