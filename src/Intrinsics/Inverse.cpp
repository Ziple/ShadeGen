#include <Intrinsics/Inverse.hpp>
#include <Intrinsics/Multiplication.hpp>
#include <Intrinsics/Power.hpp>
#include <Intrinsics/Negate.hpp>
#include <Constant.hpp>
#include <Intrinsics/Division.hpp>

Inverse::Inverse( Context* ctx, Operator* op ):
 UnaryOperator( ctx, op )
{}

Operator* Inverse::Simplified( Context* nctx )
{
    Operator* op = mySubOps[0]->Simplified(nctx);
    
    if( op->IsConstant() )
        return new Constant( nctx, 1.0 / (reinterpret_cast<Constant*>(op)->GetValue()) );
    else
        return new Inverse( nctx, op );
}

std::string Inverse::ToString(const PrintingContext& pctx) const
{
    return "(1/" + mySubOps[0]->ToString(pctx.InlineWriting()) + ")";
}