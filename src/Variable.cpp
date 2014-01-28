#include <Variable.hpp>
#include <Constant.hpp>
#include <GlobalContext.hpp>

Variable::Variable(
    Context* ctx,
    const std::string& name,
    Type* type ) :
 Operator( ctx, std::vector<Operator*>(), type ),
 myName( name )
{
    myContext->RegisterVariableName( name );
}

bool Variable::IsVariable() const {return true;}

std::string Variable::ToString( const PrintingContext& pctx ) const {return myName; }
