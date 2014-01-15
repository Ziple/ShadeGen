#include <Intrinsics/Log.hpp>
#include <Constant.hpp>
#include <Intrinsics/Division.hpp>

#include <cmath>

Log::Log( Context* ctx, Operator* op) :
 UnaryOperator( ctx, op )
{}

Operator* Log::Simplified( Context* nctx )
{
    Operator* op = mySubOps[0]->Simplified(nctx);
    
    if( op->IsConstant() )
        return new Constant( nctx, std::log( reinterpret_cast<Constant*>(op)->GetValue() ) );
    else
        return op;
}

std::string Log::ToString(const PrintingContext& pctx) const {return "ln(" + mySubOps[0]->ToString(pctx.InlineWriting()) + ")"; }