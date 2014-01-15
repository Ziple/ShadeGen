#ifndef __SC_SCALARTYPES_HPP__
#define __SC_SCALARTYPES_HPP__

#include "Type.hpp"

#include <string>

class ScalarType: public Type
{
public:
    
    ScalarType( GlobalContext* ctx, const std::string& name ):
     Type( ctx, name)
    {}
    
    virtual ~ScalarType() {}
    
    bool IsScalar() const {return true;}
};


class BoolType: public ScalarType
{
public:
    
    BoolType( GlobalContext* ctx ):
     ScalarType( ctx, "bool" )
    {}
    
};

class Uint32Type: public ScalarType
{
public:
    
    Uint32Type( GlobalContext* ctx ):
     ScalarType( ctx, "uint" )
    {}
    
};

class Int32Type: public ScalarType
{
public:
    
    Int32Type( GlobalContext* ctx):
     ScalarType( ctx, "int" )
    {}
    
};

class HalfType: public ScalarType
{
public:
    
    HalfType( GlobalContext* ctx ):
     ScalarType( ctx, "half" )
    {}
    
};

class FloatType: public ScalarType
{
public:
    
    FloatType( GlobalContext* ctx ):
     ScalarType( ctx, "float" )
    {}
    
};

#endif // __SC_SCALARTYPES_HPP__