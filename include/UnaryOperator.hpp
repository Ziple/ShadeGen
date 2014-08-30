#ifndef __SC_UNARYOPERATOR_HPP__
#define __SC_UNARYOPERATOR_HPP__

#include "Operator.hpp"

#include <Utils/SharablePointer.hpp>

class UnaryOperator : public Operator, public Sharable<UnaryOperator>
{
    public:
        
        UnaryOperator( Context* ctx, Operator* op );

        void ResolveType();
};

#endif // __SC_UNARYOPERATOR_HPP__
