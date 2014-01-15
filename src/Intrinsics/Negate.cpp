#include <Intrinsics/Negate.hpp>
#include <Constant.hpp>

Negate::Negate( Context* ctx, Operator* op) :
UnaryOperator( ctx, op )
{}

Operator* Negate::Simplified( Context* nctx )
{
    Operator* sop = mySubOps[0]->Simplified(nctx);
    
    if( sop->IsConstant() )
        return new Constant( nctx, - reinterpret_cast<Constant*>(sop)->GetValue() );
    else
        return new Negate( nctx, sop );
}

std::string Negate::ToString(const PrintingContext& pctx) const
{
    return "(-" + mySubOps[0]->ToString(pctx.InlineWriting()) + ")";
}
