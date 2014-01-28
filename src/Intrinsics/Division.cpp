#include <Intrinsics/Division.hpp>
#include <Intrinsics/Substraction.hpp>
#include <Intrinsics/Power.hpp>
#include <Intrinsics/Multiplication.hpp>
#include <Constant.hpp>
#include <Intrinsics/Inverse.hpp>
#include <Types/Type.hpp>
#include <Context.hpp>

Division::Division( Context* ctx, Operator* first, Operator* second ):
    BinaryOperator( ctx, first, second )
    {}

Operator* Division::Simplified(
    Context* nctx,
    TypeCorrespondanceTable& table )
{
    Operator* fp = mySubOps[0]->Simplified(nctx, table);
    Operator* fs = mySubOps[1]->Simplified(nctx, table);
    
    if( fp->IsNull() )
        return new Constant( nctx, 0.0, table[GetType()] );
    else if( fp->IsOne() )
        return new Inverse( nctx, fs );
    else if( fp->IsConstant() && fs->IsConstant() )
    {
        Constant* cfp = reinterpret_cast<Constant*>(fp);
        Constant* cfs = reinterpret_cast<Constant*>(fs);
        
        return new Constant( nctx, cfp->GetValue() / cfs->GetValue(), table[GetType()] );
    }
    else
        return new Division( nctx, fp, fs );
}

std::string Division::ToString(const PrintingContext& pctx) const
{
    return "(" + mySubOps[0]->ToString(pctx.InlineWriting()) + "/" + mySubOps[1]->ToString(pctx.InlineWriting()) + ")";
}

void Division::ResolveTypes()
{
    Operator* fst = mySubOps[0];
    fst->ResolveTypes();

    Operator* snd = mySubOps[1];
    snd->ResolveTypes();

    GlobalContext* gctx = reinterpret_cast<GlobalContext*>( myContext->GetGlobalContext() );

    Type* fstType = fst->GetType();
    Type* sndType = snd->GetType();

    if( sndType->IsScalar() )
        myType = fstType;
    else
        myType = new ErrorType(
            reinterpret_cast<GlobalContext*>( myContext->GetGlobalContext() ),
            "Unknown multiplication" );
}