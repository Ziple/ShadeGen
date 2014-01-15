#include <Intrinsics/Power.hpp>
#include <Intrinsics/Addition.hpp>
#include <Intrinsics/Multiplication.hpp>
#include <Intrinsics/Substraction.hpp>
#include <Intrinsics/Division.hpp>
#include <Constant.hpp>
#include <Intrinsics/Log.hpp>

#include <cmath>

Power::Power( Context* ctx, Operator* first, Operator* second) :
 BinaryOperator( ctx, first, second )
{}

Operator* Power::Simplified( Context* nctx )
{
    Operator* sf = mySubOps[0]->Simplified(nctx);
    Operator* ss = mySubOps[1]->Simplified(nctx);
    
    if( sf->IsConstant() && ss->IsConstant() )
    {
        Constant* csf = reinterpret_cast<Constant*>(sf);
        Constant* css = reinterpret_cast<Constant*>(ss);
        
        return new Constant( nctx, std::pow(csf->GetValue(), css->GetValue() ) );
    }
    else if( ss->IsNull() )
        return new Constant( nctx, 1.0 );
    else if( ss->IsOne() )
        return sf;
    else
        return new Power( nctx, sf, ss );
}

std::string Power::ToString(const PrintingContext& pctx) const
{
    return "(" + mySubOps[0]->ToString(pctx.InlineWriting()) + "^" + mySubOps[1]->ToString(pctx.InlineWriting()) + ")";
}