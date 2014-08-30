#ifndef __SC_CONSTANT_HPP__
#define __SC_CONSTANT_HPP__

#include "Operator.hpp"
#include <Utils/SharablePointer.hpp>

#include <sstream>

class Type;

class Constant : public Operator, public Sharable<Constant>
{
public:
    
    Constant(
        Context* ctx,
        double val,
        Type* type = 0 );

    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable )
    {
        return new Constant( nctx, myValue, correspondanceTable[GetType()] );
    }
    
    bool IsConstant() const;
    
    bool IsNull() const;
    
    bool IsOne() const;
    
    double GetValue() const ;
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
protected:
    
    double myValue;
};

#endif // __SC_CONSTANT_HPP__
