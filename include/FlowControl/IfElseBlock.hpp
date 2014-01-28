#ifndef __IFELSEBLOCK_HPP__
#define __IFELSEBLOCK_HPP__

#include "../Instructions/InstructionList.hpp"

class IfElseBlock: public Instruction
{
public:
    
    IfElseBlock( Context* ctx,
              const std::vector<Operator*> conditions,
              const std::vector<InstructionList*> blocks,
              InstructionList* elseBlock
               );
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );
    
protected:
    bool myHasElseBlock;
};

#endif /* __IFELSEBLOCK_HPP__ */