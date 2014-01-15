#include <Constant.hpp>

Constant::Constant(Context* ctx, double val) :
 Operator( ctx ),
 myValue( val )
{}

bool Constant::IsConstant() const { return true; }

bool Constant::IsNull() const { return (myValue == 0.0); }

bool Constant::IsOne() const { return (myValue == 1.0); }

double Constant::GetValue() const {return myValue;}

std::string Constant::ToString( const PrintingContext& pctx ) const {
    std::ostringstream oss;
    oss << myValue;
    return oss.str();
}
