#include <UnaryOperator.hpp>

UnaryOperator::UnaryOperator( Context* ctx, Operator* op) :
Operator( ctx )
{
    mySubOps.push_back(op);
}

void UnaryOperator::ResolveType()
{
    Operator* op = mySubOps[0];
    op->ResolveTypes();

    myType = op->GetType();
}