#include <BinaryOperator.hpp>
#include <algorithm>

BinaryOperator::BinaryOperator( Context* ctx, Operator* first, Operator* second ):
 Operator( ctx )
{
    mySubOps.push_back(first);
    mySubOps.push_back(second);
}