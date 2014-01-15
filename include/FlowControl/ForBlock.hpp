#ifndef __FORBLOCK_HPP__
#define __FORBLOCK_HPP__

#include "../Instructions/Instruction.hpp"

class ForBlock: public Instruction
{
public:
    
    ForBlock( Context* ctx,
              Instruction* start,
              Operator* condition,
              Instruction* incr,
              Instruction* block
               );
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
    Operator* Simplified( Context* nctx );
};

#endif /* __FORBLOCK_HPP__ */