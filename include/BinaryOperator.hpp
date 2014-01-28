#ifndef __SC_BINRARYOPERATOR_HPP__
#define __SC_BINRARYOPERATOR_HPP__

#include "Operator.hpp"

class BinaryOperator: public Operator
{
    public:
        
        BinaryOperator( Context* ctx, Operator* first, Operator* second );

        void ResolveTypes();
};

#endif // __SC_BINRARYOPERATOR_HPP__
