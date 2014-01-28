#include <Intrinsics/Substraction.hpp>
#include <Constant.hpp>
#include <Intrinsics/Negate.hpp>

Substraction::Substraction( Context* ctx, Operator* first, Operator* second) :
BinaryOperator( ctx, first, second )
{}

Operator* Substraction::Simplified(
    Context* nctx,
    TypeCorrespondanceTable& table )
{
    Operator* sf = mySubOps[0]->Simplified(nctx, table);
    Operator* ss = mySubOps[1]->Simplified(nctx, table);
    
    if( sf->IsConstant() && ss->IsConstant() )
    {
        Constant* csf = reinterpret_cast<Constant*>(sf);
        Constant* css = reinterpret_cast<Constant*>(ss);
        
        double v = csf->GetValue() - css->GetValue();
        return new Constant( nctx, v );
    }
    else if( sf->IsNull() )
        return new Negate( nctx, ss );
    else if( ss->IsNull() )
        return sf;
    else
        return new Substraction( nctx, sf, ss );
}

std::string Substraction::ToString(const PrintingContext& pctx) const
{
    return "(" + mySubOps[0]->ToString(pctx.InlineWriting()) + "-" + mySubOps[1]->ToString(pctx.InlineWriting()) + ")";
}
