#ifndef __IFELSEBLOCK_HPP__
#define __IFELSEBLOCK_HPP__

#include "../Instructions/Instruction.hpp"

class IfElseBlock: public Instruction
{
public:
    
    IfElseBlock( Context* ctx,
              const std::vector<Operator*> conditions,
              const std::vector<Instruction*> blocks,
              Instruction* elseBlock
               );
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
    Operator* Simplified( Context* nctx );
    
protected:
    bool myHasElseBlock;
};

#endif /* __IFELSEBLOCK_HPP__ */