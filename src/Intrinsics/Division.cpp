#include <Intrinsics/Division.hpp>
#include <Intrinsics/Substraction.hpp>
#include <Intrinsics/Power.hpp>
#include <Intrinsics/Multiplication.hpp>
#include <Constant.hpp>
#include <Intrinsics/Inverse.hpp>

Division::Division( Context* ctx, Operator* first, Operator* second ):
    BinaryOperator( ctx, first, second )
    {}

Operator* Division::Simplified( Context* nctx )
{
    Operator* fp = mySubOps[0]->Simplified(nctx);
    Operator* fs = mySubOps[1]->Simplified(nctx);
    
    if( fp->IsNull() )
        return new Constant( nctx, 0.0 );
    else if( fp->IsOne() )
        return new Inverse( nctx, fs );
    else if( fp->IsConstant() && fs->IsConstant() )
    {
        Constant* cfp = reinterpret_cast<Constant*>(fp);
        Constant* cfs = reinterpret_cast<Constant*>(fs);
        
        return new Constant( nctx, cfp->GetValue() / cfs->GetValue() );
    }
    else
        return new Division( nctx, fp, fs );
}

std::string Division::ToString(const PrintingContext& pctx) const
{
    return "(" + mySubOps[0]->ToString(pctx.InlineWriting()) + "/" + mySubOps[1]->ToString(pctx.InlineWriting()) + ")";
}