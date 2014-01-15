#include <Function.hpp>
#include <GlobalContext.hpp>
#include <Variable.hpp>
#include <Instructions/InstructionList.hpp>
#include <algorithm>

Function::Function(
    Context* ctx,
    const std::string& name,
    InstructionList* instructions ):
 Operator( ctx ),
 myName( name ),
 myLocalContext( ctx )
{
    myContext->RegisterFunction( this );
    if( instructions != 0 )
        mySubOps.push_back( instructions );
}

Function::~Function()
{
    myContext->UnregisterFunction( this );
}

Operator* Function::Simplified( Context* nctx )
{
    Instruction* simpls = 0;
    
    if( mySubOps.size() > 0 )
        simpls = reinterpret_cast<Instruction*>( mySubOps[0]->Simplified(nctx));
    
    if( simpls->IsNoOp() )
        return new Function( nctx, myName, 0 );
    else if( simpls->IsInstructionList() )
        return new Function( nctx, myName, reinterpret_cast<InstructionList*>(simpls) );
    else
    {
        InstructionList* l = new InstructionList( nctx );
        l->PushBack(simpls);
        return new Function( nctx, myName, l );
    }
}

std::string Function::ToString( const PrintingContext& pctx ) const
{
    std::string tabs = pctx.Tabs();
    std::string str = tabs + myName + "( ";
    
    const std::vector<const Variable*> vars = GetVariables();
    
    if( vars.size() > 0 )
    {
        for( size_t i = 0; i < vars.size() - 1; i++ )
            str += (vars[i]->ToString(pctx.InlineWriting()) + ", ");
        
        str += vars[vars.size()-1]->ToString(pctx.InlineWriting());
    }
    str+= " )\n" + tabs + "{\n";
    
    if( mySubOps.size() > 0 )
        str += mySubOps[0]->ToString( pctx.AddTab() );
    str += tabs + "}";
    return str;
}