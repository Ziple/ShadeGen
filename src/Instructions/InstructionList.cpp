#include <Instructions/InstructionList.hpp>
#include <Instructions/NoOperation.hpp>

InstructionList::InstructionList(
    Context* ctx,
    Instruction* ins ):
 Instruction( ctx )
{
    mySubOps.push_back( ins );
    BuildReturnInstructionCache();
}

InstructionList::InstructionList(
    Context* ctx,
    std::vector<Instruction*> ops
):
 Instruction( ctx )
{
    mySubOps.insert( mySubOps.end(), ops.begin(), ops.end() );
    BuildReturnInstructionCache();
}

bool InstructionList::IsInstructionList() const
{
    return true;
}

void InstructionList::PushBack( Instruction* op )
{
    mySubOps.push_back( op );
}

std::string InstructionList::ToString( const PrintingContext& pctx ) const
{
    std::string str;
    std::string tabs = pctx.Tabs();
    
    if( mySubOps.size() > 0 )
    {
        for( size_t i = 0; i < mySubOps.size()-1; i++ )
            str += mySubOps[i]->ToString(pctx) + "\n";
        str += mySubOps[mySubOps.size()-1]->ToString(pctx);
    }
    return str;
}

Operator* InstructionList::Simplified(
    Context* nctx,
    TypeCorrespondanceTable& table )
{
    std::vector<Instruction*> sops;
    
    for( size_t i = 0; i < mySubOps.size(); i++ )
    {
        Instruction* sop = reinterpret_cast<Instruction*>( mySubOps[i]->Simplified(nctx, table) );
        
        if( sop->IsNoOp() == false )
            sops.push_back( sop );
    }
    
    if( sops.size() > 0 )
        return new InstructionList( nctx, sops );
    else
        return new NoOperation( nctx );
}

void InstructionList::BuildReturnInstructionCache()
{
}