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
    
    Type* Clone( GlobalContext* nctx ) const { return new ScalarType( nctx, myTypeName ); }

    virtual ~ScalarType() {}
    
    bool IsScalar() const {return true;}
};


class BoolType: public ScalarType
{
public:
    
    BoolType( GlobalContext* ctx ):
     ScalarType( ctx, "bool" )
    {}
    
    const std::string& GetReducedName() const { static std::string b = "b"; return b; }
};

class Uint32Type: public ScalarType
{
public:
    
    Uint32Type( GlobalContext* ctx ):
     ScalarType( ctx, "uint" )
    {}
    
    const std::string& GetReducedName() const { static std::string b = "u"; return b; }
};

class Int32Type: public ScalarType
{
public:
    
    Int32Type( GlobalContext* ctx):
     ScalarType( ctx, "int" )
    {}
    
    const std::string& GetReducedName() const { static std::string b = "i"; return b; }
};

class HalfType: public ScalarType
{
public:
    
    HalfType( GlobalContext* ctx ):
     ScalarType( ctx, "half" )
    {}
  
    const std::string& GetReducedName() const { static std::string b = "h"; return b; }
};

class FloatType: public ScalarType
{
public:
    
    FloatType( GlobalContext* ctx ):
     ScalarType( ctx, "float" )
    {}
    
    const std::string& GetReducedName() const { static std::string b = "f"; return b; }
};

class DoubleType: public ScalarType
{
public:
    
    DoubleType( GlobalContext* ctx ):
     ScalarType( ctx, "double" )
    {}
    
    const std::string& GetReducedName() const { static std::string b = "d"; return b; }
};

#endif // __SC_SCALARTYPES_HPP__