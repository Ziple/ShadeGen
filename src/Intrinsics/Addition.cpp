#include <Intrinsics/Addition.hpp>
#include <Constant.hpp>

#include <algorithm>

Addition::Addition(Context* ctx, Operator* first, Operator* second) :
 BinaryOperator( ctx, first, second )
{}

Operator* Addition::Simplified(
    Context* nctx,
    TypeCorrespondanceTable& correspondanceTable )
{
    Operator* sf = mySubOps[0]->Simplified(nctx, correspondanceTable);
    Operator* ss = mySubOps[1]->Simplified(nctx, correspondanceTable);
    
    if( sf->IsConstant() && ss->IsConstant() )
    {
        Constant* csf = reinterpret_cast<Constant*>(sf);
        Constant* css = reinterpret_cast<Constant*>(ss);
        
        double v = csf->GetValue() + css->GetValue();
        return new Constant( nctx, v, correspondanceTable[GetType()] );
    }
    else if( sf->IsNull() )
        return ss;
    else if( ss->IsNull() )
        return sf;
    else
        return new Addition( nctx, sf, ss );
}

std::string Addition::ToString(const PrintingContext& pctx) const
{
    return "(" + mySubOps[0]->ToString(pctx.InlineWriting() ) + "+" + mySubOps[1]->ToString(pctx.InlineWriting()) + ")";
}