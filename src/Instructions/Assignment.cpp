#include <Instructions/Assignment.hpp>
#include <Variable.hpp>
#include <Instructions/NoOperation.hpp>

Assignment::Assignment(
    Context* ctx,
    Variable* lval,
    Operator* rval ):
 Instruction( ctx )
{
    mySubOps.push_back(lval);
    mySubOps.push_back(rval);
}

std::string Assignment::ToString( const PrintingContext& pctx ) const
{
    return pctx.Tabs() + mySubOps[0]->ToString( pctx.InlineWriting() ) + " = "
           + mySubOps[1]->ToString( pctx.InlineWriting() ) + ";";
}

Operator* Assignment::Simplified(
    Context* nctx,
    TypeCorrespondanceTable& table )
{
    Variable* slval = reinterpret_cast<Variable*>( mySubOps[0]->Simplified(nctx, table) );
    Operator* srval = mySubOps[1]->Simplified(nctx, table);
    
    if( srval->IsVariable() )
    {
        Variable* r = reinterpret_cast<Variable*>(srval);
        
        if( slval->ToString() == srval->ToString() )
            return new NoOperation( nctx );
    }

    return new Assignment( nctx, slval, srval );
}