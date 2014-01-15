#ifndef __SC_MATRICIALTYPES_HPP__
#define __SC_MATRICIALTYPES_HPP__

#include "Type.hpp"
#include "ScalarTypes.hpp"

#include <string>

template< typename T, size_t L, size_t R >
class MatricialType: public Type
{
public:
    
    MatricialType( GlobalContext* ctx, const std::string& name ):
     Type( ctx, name)
    {}
    
    virtual ~MatricialType() {}
    
    bool IsScalar() const {return (L==1) && (R==1);}
    
    bool IsMatricial() const {return (L>1) || (R>1);}
};


// vector types
template< typename T >
class Vector2Type: public MatricialType<T, 2, 1 >
{
public:
    
    Vector2Type( GlobalContext* ctx, const std::string& name ):
     MatricialType<T, 2, 1 >( ctx, name )
    {}
};

template< typename T >
class Vector3Type: public MatricialType<T, 3, 1 >
{
public:
    
    Vector3Type( GlobalContext* ctx, const std::string& name ):
     MatricialType<T, 3, 1 >( ctx, name )
    {}
};

template< typename T >
class Vector4Type: public MatricialType<T, 4, 1 >
{
public:
    
    Vector4Type( GlobalContext* ctx, const std::string& name ):
     MatricialType<T, 4, 1 >( ctx, name )
    {}
};

// realisations
class Vector2FloatType: public Vector2Type<FloatType>
{
public:
    Vector2FloatType( GlobalContext* ctx ):
     Vector2Type( ctx, "vec2" )
    {}
};

class Vector3FloatType: public Vector3Type<FloatType>
{
public:
    Vector3FloatType( GlobalContext* ctx ):
     Vector3Type( ctx, "vec3" )
    {}
};

class Vector4FloatType: public Vector4Type<FloatType>
{
public:
    Vector4FloatType( GlobalContext* ctx ):
     Vector4Type( ctx, "vec4" )
    {}
};


// matricial types
template< typename T >
class Matrix4x4Type: public MatricialType<T, 4, 4 >
{
public:
    
    Matrix4x4Type( GlobalContext* ctx, const std::string& name ):
     MatricialType<T, 4, 4 >( ctx, name )
    {}
};

template< typename T >
class Matrix3x4Type: public MatricialType<T, 3, 4 >
{
public:
    
    Matrix3x4Type( GlobalContext* ctx, const std::string& name ):
     MatricialType<T, 3, 4 >( ctx, name )
    {}
};

template< typename T >
class Matrix4x3Type: public MatricialType<T, 4, 3 >
{
public:
    
    Matrix4x3Type( GlobalContext* ctx, const std::string& name ):
     MatricialType<T, 4, 3 >( ctx, name )
    {}
};

template< typename T >
class Matrix3x3Type: public MatricialType<T, 3, 3 >
{
public:
    
    Matrix3x3Type( GlobalContext* ctx, const std::string& name ):
     MatricialType<T, 3, 3 >( ctx, name )
    {}
};

//Realisations
class Matrix4x4FloatType: public Matrix4x4Type<FloatType>
{
public:
    
   Matrix4x4FloatType( GlobalContext* ctx ):
     Matrix4x4Type( ctx, "matrix" )
    {}
};

class Matrix3x4FloatType: public Matrix3x4Type<FloatType>
{
public:
    
   Matrix3x4FloatType( GlobalContext* ctx ):
     Matrix3x4Type( ctx, "matrix3x4" )
    {}
};

class Matrix4x3FloatType: public Matrix4x3Type<FloatType>
{
public:
    
   Matrix4x3FloatType( GlobalContext* ctx ):
     Matrix4x3Type( ctx, "matrix4x3" )
    {}
};

class Matrix3x3FloatType: public Matrix3x3Type<FloatType>
{
public:
    
   Matrix3x3FloatType( GlobalContext* ctx ):
     Matrix3x3Type( ctx, "matrix3x3" )
    {}
};

#endif // __SC_MATRICIALTYPES_HPP__