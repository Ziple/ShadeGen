#include <BinaryOperator.hpp>
#include <Types/Type.hpp>
#include <GlobalContext.hpp>

#include <algorithm>

BinaryOperator::BinaryOperator( Context* ctx, Operator* first, Operator* second ):
 Operator( ctx )
{
    mySubOps.push_back(first);
    mySubOps.push_back(second);
}

void BinaryOperator::ResolveTypes()
{
    Operator* fst = mySubOps[0];
    fst->ResolveTypes();

    Operator* snd = mySubOps[1];
    snd->ResolveTypes();

    if( fst->GetType() == snd->GetType() )
        myType = fst->GetType();
    else
        myType = new ErrorType(
            reinterpret_cast<GlobalContext*>( myContext->GetGlobalContext() ),
            "Types mismatch" );
}