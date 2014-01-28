#include <FlowControl/IfElseBlock.hpp>
#include <Instructions/NoOperation.hpp>

IfElseBlock::IfElseBlock(
    Context* ctx,
    const std::vector<Operator*> conditions,
    const std::vector<InstructionList*> blocks,
    InstructionList* elseBlock
    ):
 Instruction( ctx ),
 myHasElseBlock(elseBlock != 0)
{
    mySubOps.insert( mySubOps.end(), conditions.begin(), conditions.end() );
    mySubOps.insert( mySubOps.end(), blocks.begin(), blocks.end() );
    
    if( myHasElseBlock )
        mySubOps.push_back( elseBlock );
}

std::string IfElseBlock::ToString( const PrintingContext& pctx ) const
{
    std::string tabs = pctx.Tabs();
    
    size_t numPairs = 0;
    
    if( myHasElseBlock )
        numPairs = (mySubOps.size() - 1)/2;
    else
        numPairs = mySubOps.size()/2;
    
    std::string str;
    
    if( numPairs > 0 )
    {
        str += tabs + "if( " + mySubOps[0]->ToString( pctx.InlineWriting() ) + " )\n" + tabs + "{\n"
               + mySubOps[numPairs + 0]->ToString( pctx.AddTab() )
               + "\n" + tabs + "}\n";
        
        for( size_t i = 1; i < numPairs; i++ )
        {
           str += tabs + "else if( " + mySubOps[i]->ToString( pctx.InlineWriting() ) + " )\n" + tabs + "{\n"
               + mySubOps[numPairs + i]->ToString( pctx.AddTab() )
               + "\n" + tabs + "}\n";
        }
        
        if( myHasElseBlock )
            str += tabs + "else\n"+ tabs + "{\n" + mySubOps[numPairs*2]->ToString( pctx.AddTab() ) + "\n" + tabs + "}\n";
        
    }
    
    return str;
}

Operator* IfElseBlock::Simplified(
    Context* nctx,
    TypeCorrespondanceTable& table )
{
    std::vector<Operator*> sconditions;
    std::vector<InstructionList*> sblocks;
    InstructionList* selseBlock = myHasElseBlock ? reinterpret_cast<InstructionList*>( mySubOps[mySubOps.size()-1]->Simplified(nctx, table) ) : 0;
    
    size_t numPairs = 0;
    
    if( myHasElseBlock )
        numPairs = (mySubOps.size() - 1)/2;
    else
        numPairs = mySubOps.size()/2;
    
    std::string str;
    
     for( size_t i = 0; i < numPairs; i++ )
     {
         Operator* scondition = mySubOps[i]->Simplified(nctx, table);
         InstructionList* sblock = reinterpret_cast<InstructionList*>( mySubOps[ numPairs + i ]->Simplified(nctx, table) );
         
         if( scondition->IsOne() )
             return sblock;
         else if( !(scondition->IsConstant()) )
         {
             sconditions.push_back( scondition );
             sblocks.push_back( sblock );
         }
     }
    
    if( sconditions.size() > 0 )
        return new IfElseBlock( nctx, sconditions, sblocks, selseBlock );
    else if( selseBlock != 0 )
        return selseBlock;
    else
        return new NoOperation( nctx );
}