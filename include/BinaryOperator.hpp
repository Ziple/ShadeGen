#ifndef __SC_BINRARYOPERATOR_HPP__
#define __SC_BINRARYOPERATOR_HPP__

#include "Operator.hpp"
#include <Utils/SharablePointer.hpp>

class BinaryOperator : public Operator, public Sharable<BinaryOperator>
{
public:
        
    BinaryOperator( Operator::Ptr first, Operator::Ptr second );

    void ResolveTypes();

protected:

	Operator::Ptr myFirst;
	Operator::Ptr mySecond;
};

#endif // __SC_BINRARYOPERATOR_HPP__
