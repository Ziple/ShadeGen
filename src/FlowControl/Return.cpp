#include <FlowControl/Return.hpp>

Return::Return(
    Context* ctx,
    Operator* op ):
 Instruction(ctx)
{
    mySubOps.push_back(op);
}

std::string Return::ToString( const PrintingContext& pctx ) const
{
    return pctx.Tabs() + "return " + mySubOps[0]->ToString( pctx.InlineWriting() ) + ";";
}

Operator* Return::Simplified( Context* nctx )
{
    return new Return( nctx, mySubOps[0]->Simplified(nctx) );
}