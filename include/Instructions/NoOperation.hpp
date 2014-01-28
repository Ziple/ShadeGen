#ifndef __NOOPERATION_HPP__
#define __NOOPERATION_HPP__

#include "Instruction.hpp"
#include <Context.hpp>

class NoOperation: public Instruction
{
public:
    
    NoOperation( Context* ctx): Instruction(ctx)
    {
        myType = ctx->GetTypeByName( "void" );
    }
    
    bool IsNoOp() const {return true;}

    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable ) { return new NoOperation( nctx ); }
};

#endif /* __NOOPERATION_HPP__ */