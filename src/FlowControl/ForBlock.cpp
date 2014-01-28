#include <FlowControl/ForBlock.hpp>
#include <Instructions/NoOperation.hpp>

ForBlock::ForBlock(
    Context* ctx,
    Instruction* start,
    Operator* cond,
    Instruction* incr,
    InstructionList* block ):
 Instruction( ctx )
{
    mySubOps.push_back( start );
    mySubOps.push_back( cond );
    mySubOps.push_back( incr );
    mySubOps.push_back( block );
}

std::string ForBlock::ToString( const PrintingContext& pctx ) const
{
    std::string tabs = pctx.Tabs();
    std::string str = tabs + "for( ";
    if( mySubOps[0] != 0 )
        str += mySubOps[0]->ToString( pctx.InlineWriting() );
    str += " ; ";
    if( mySubOps[1] != 0 )
        str += mySubOps[1]->ToString( pctx.InlineWriting() );
    str += " ; ";
    if( mySubOps[2] != 0 )
        str += mySubOps[2]->ToString( pctx.InlineWriting() );
    str += " )\n" + tabs + "{\n";
    if( mySubOps[3] != 0 )
        str += mySubOps[3]->ToString( pctx.AddTab() );
    str += "\n" + tabs + "}\n";
    
    return str;
}

Operator* ForBlock::Simplified(
    Context* nctx,
    TypeCorrespondanceTable& table )
{
    Instruction *sstart, *sincr;
    InstructionList *sblock;
    Operator *scond;
    sstart = mySubOps[0] != 0 ? reinterpret_cast<Instruction*>( mySubOps[0]->Simplified( nctx, table ) ): 0;
    scond = mySubOps[1] != 0 ? mySubOps[1]->Simplified( nctx, table ) : 0;
    sincr = mySubOps[2] != 0 ? reinterpret_cast<Instruction*>( mySubOps[2]->Simplified( nctx, table ) ): 0;
    sblock = mySubOps[3] != 0 ? reinterpret_cast<InstructionList*>( mySubOps[3]->Simplified( nctx, table ) ): 0;
    
    // if the condition is never met or there is absolutely
    // nothing in the loop, remove the for block and replace it with a noop
    if( (
            scond != 0
            && scond->IsConstant()
            && !(scond->IsOne())
        )
        ||
        (
            ( sstart == 0 || sstart->IsNoOp() )
            && ( scond == 0 || scond->IsNoOp() )
            && ( sincr == 0 || sincr->IsNoOp() )
            && ( sblock == 0 || sblock->IsNoOp() )
        )
      )
        return new NoOperation( nctx );
    
    return new ForBlock( nctx, sstart, scond, sincr, sblock );
}