#ifndef __FORBLOCK_HPP__
#define __FORBLOCK_HPP__

#include "../Instructions/InstructionList.hpp"

class ForBlock: public Instruction
{
public:
    
    ForBlock( Context* ctx,
              Instruction* start,
              Operator* condition,
              Instruction* incr,
              InstructionList* block
               );
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );
};

#endif /* __FORBLOCK_HPP__ */