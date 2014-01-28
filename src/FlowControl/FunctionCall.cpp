#include <FlowControl/FunctionCall.hpp>
#include <Function.hpp>

#include <algorithm>

FunctionCall::FunctionCall(
    Context* ctx,
    Function* called, 
    const std::vector<Operator*>& args
          ):
    Instruction( ctx ),
    myCalledFunction( called)
{
    mySubOps = args;
}

std::string FunctionCall::ToString( const PrintingContext& pctx ) const
{
    std::string tabs = pctx.Tabs();
    std::string str;
    
    if( !pctx.inlineWriting )
        str += tabs;
    
    str += myCalledFunction->GetName() + "( ";
    
    if( mySubOps.size() > 0 )
    {
        for( size_t i = 0; i < mySubOps.size()-1; i++ )
            str += mySubOps[i]->ToString( pctx.InlineWriting() ) + ", ";
        
        str += mySubOps[ mySubOps.size() - 1 ]->ToString( pctx.InlineWriting() );
    }
    
    str += " )";
    
    if( !pctx.inlineWriting )
        str += ";\n";
        
    return str;
}

Operator* FunctionCall::Simplified(
    Context* nctx,
    TypeCorrespondanceTable& table )
{
    std::vector<Operator*> sargs;
    for( std::vector<Operator*>::iterator it = mySubOps.begin();
        it != mySubOps.end();
        it++ )
        sargs.push_back( (*it)->Simplified( nctx, table ) );
    
    return new FunctionCall( nctx, reinterpret_cast<Function*>(myCalledFunction->Simplified(nctx, table)), sargs );
}