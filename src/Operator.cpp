#include <Operator.hpp>
#include <GlobalContext.hpp>
#include <Variable.hpp>

Operator::Operator(
    Context* ctx,
    const std::vector<Operator*> subops,
    Type* type ):
    myContext( ctx ),
    mySubOps( subops ),
    myType( type )
{
    myContext->RegisterOperator( this );

    if( type == 0 )
        myType = ctx->GetTypeByName( "unknown" );
}
        
Operator::~Operator()
{
    myContext->UnregisterOperator( this );
}

std::vector< const Variable* > Operator::GetVariables() const
{   
    std::vector<const Variable*> ret;
    
    if( IsVariable() )
        ret.push_back(reinterpret_cast<const Variable*>(this));
    
    for( std::vector<Operator*>::const_iterator iit = mySubOps.begin();
        iit != mySubOps.end();
        iit++ )
   {
        const std::vector<const Variable*>& sv = (*iit)->GetVariables();
        for( std::vector<const Variable*>::const_iterator it = sv.begin();
            it != sv.end();
            it++ )
            if( std::find( ret.begin(), ret.end(), *it ) == ret.end() )
                ret.push_back( *it );
    }
    return ret;
}

bool Operator::IsInstruction() const { return false; }

bool Operator::IsNoOp() const {return false;}

bool Operator::IsVariable() const {return false;}

bool Operator::IsConstant() const { return false; }

bool Operator::IsNull() const { return false; }

bool Operator::IsOne() const { return false; }

std::string Operator::ToString( const PrintingContext& pctx ) const {return std::string(); }