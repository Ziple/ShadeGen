#include <Intrinsics/Multiplication.hpp>
#include <Intrinsics/Addition.hpp>
#include <Constant.hpp>

Multiplication::Multiplication( Context* ctx, Operator* first, Operator* second) :
BinaryOperator( ctx, first, second )
{}

Operator* Multiplication::Simplified( Context* nctx )
{
    Operator* sf = mySubOps[0]->Simplified(nctx);
    Operator* ss = mySubOps[1]->Simplified(nctx);
    
    if( sf->IsConstant() && ss->IsConstant() )
    {
        Constant* csf = reinterpret_cast<Constant*>(sf);
        Constant* css = reinterpret_cast<Constant*>(ss);
        
        double v = csf->GetValue() * css->GetValue();
        return new Constant( nctx, v );
    }
    else if( sf->IsNull() || ss->IsNull() )
        return new Constant( nctx, 0.0 );
    else if( sf->IsOne() )
        return ss;
    else if( ss->IsOne() )
        return sf;
    else
        return new Multiplication( nctx, sf, ss );
}

std::string Multiplication::ToString(const PrintingContext& pctx) const
{
    return "(" + mySubOps[0]->ToString(pctx.InlineWriting()) + "*" + mySubOps[1]->ToString(pctx.InlineWriting()) + ")";
}