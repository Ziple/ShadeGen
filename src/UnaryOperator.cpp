#include <UnaryOperator.hpp>

UnaryOperator::UnaryOperator( Context* ctx, Operator* op) :
Operator( ctx )
{
    mySubOps.push_back(op);
}
