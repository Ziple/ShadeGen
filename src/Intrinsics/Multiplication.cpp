#include <Intrinsics/Multiplication.hpp>
#include <Intrinsics/Addition.hpp>
#include <Constant.hpp>
#include <Types/Type.hpp>
#include <Types/MatricialTypes.hpp>

#include <string>

Multiplication::Multiplication( Context* ctx, Operator* first, Operator* second) :
BinaryOperator( ctx, first, second )
{}

Operator* Multiplication::Simplified(
    Context* nctx,
    TypeCorrespondanceTable& table )
{
    Operator* sf = mySubOps[0]->Simplified(nctx, table );
    Operator* ss = mySubOps[1]->Simplified(nctx, table );
    
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

void Multiplication::ResolveTypes()
{
    Operator* fst = mySubOps[0];
    fst->ResolveTypes();

    Operator* snd = mySubOps[1];
    snd->ResolveTypes();

    GlobalContext* gctx = reinterpret_cast<GlobalContext*>( myContext->GetGlobalContext() );

    Type* fstType = fst->GetType();
    Type* sndType = snd->GetType();

    if( fstType->IsScalar() )
        myType = sndType;
    else if( sndType->IsScalar() )
        myType = fstType;
    else if( fstType->IsMatricial()
             && sndType->IsMatricial() )
    {
        MatricialType* mfstType = reinterpret_cast< MatricialType* >( fstType );
        MatricialType* msndType = reinterpret_cast< MatricialType* >( sndType );

        if( mfstType->BaseType == msndType->BaseType )
        {
            if( mfstType->Rows == msndType->Lines )
                myType = new MatricialType(
                    gctx,
                    mfstType->BaseType,
                    mfstType->Lines,
                    msndType->Rows
                    );
            else
                myType = new ErrorType( gctx, "Can't make a matrix because the dimensions can't fit" );
        }
        else
        {
            myType = new ErrorType(
                gctx,
                "Base types don't match" );
        }
    }
    else
        myType = new ErrorType(
            reinterpret_cast<GlobalContext*>( myContext->GetGlobalContext() ),
            "Unknown multiplication" );
}