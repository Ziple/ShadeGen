#include <Intrinsics/Addition.hpp>
#include <Constant.hpp>

#include <algorithm>

Addition::Addition(Operator::Ptr first, Operator::Ptr second) :
 BinaryOperator( first, second )
{}

Operator::Ptr Addition::Simplified(
    TypeCorrespondanceTable& correspondanceTable )
{
    Operator::Ptr sf = mySubOps[0]->Simplified(correspondanceTable);
    Operator::Ptr ss = mySubOps[1]->Simplified(correspondanceTable);
    
    if( sf->IsConstant() && ss->IsConstant() )
    {
        Constant* csf = reinterpret_cast<Constant*>(sf.get());
        Constant* css = reinterpret_cast<Constant*>(ss.get());
        
        double v = csf->GetValue() + css->GetValue();
        return std::make_shared<Constant>( v, correspondanceTable[GetType()] );
    }
    else if( sf->IsNull() )
        return ss;
    else if( ss->IsNull() )
        return sf;
    else
        return std::make_shared<Addition>( sf, ss );
}

std::string Addition::ToString(const PrintingContext& pctx) const
{
    return "(" + mySubOps[0]->ToString(pctx.InlineWriting() ) + "+" + mySubOps[1]->ToString(pctx.InlineWriting()) + ")";
}