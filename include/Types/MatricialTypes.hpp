#ifndef __SC_MATRICIALTYPES_HPP__
#define __SC_MATRICIALTYPES_HPP__

#include "Type.hpp"
#include "ScalarTypes.hpp"
#include <Helpers.hpp>

#include <string>


class MatricialType: public Type
{
public:
    
    static inline std::string GetMatrixName( Type* type, size_t lines, size_t rows )
    {
        return "matrix" + to_string(lines)+ "x" + to_string(rows) + type->GetReducedName();
    }

    MatricialType( GlobalContext* ctx, Type* type, size_t lines, size_t rows ):
     Type( ctx, GetMatrixName(type, lines, rows) ),
     BaseType( type ),
     Lines(lines),
     Rows(rows)
    {}

    Type* Clone( GlobalContext* nctx ) const { return new MatricialType( nctx, BaseType->Clone(nctx), Lines, Rows ); }
    
    virtual ~MatricialType() {}
    
    bool IsScalar() const {return (Lines==1) && (Rows==1);}
    
    bool IsMatricial() const {return (Lines>1) || (Rows>1);}

    Type* BaseType;
    size_t Lines, Rows;
};

// vector types
class Vector2Type: public MatricialType
{
public:
    
    Vector2Type( GlobalContext* ctx, const std::string& name, Type* type ):
     MatricialType( ctx, type, 2, 1 )
    {}
};

class Vector3Type: public MatricialType
{
public:
    
    Vector3Type( GlobalContext* ctx, const std::string& name, Type* type ):
     MatricialType( ctx, type, 3, 1 )
    {}
};

class Vector4Type: public MatricialType
{
public:
    
    Vector4Type( GlobalContext* ctx, const std::string& name, Type* type ):
     MatricialType( ctx, type, 4, 1 )
    {}
};

// realisations
class Vector2FloatType: public Vector2Type
{
public:
    Vector2FloatType( GlobalContext* ctx ):
     Vector2Type( ctx, "vec2", new FloatType(ctx) )
    {}
};

class Vector3FloatType: public Vector3Type
{
public:
    Vector3FloatType( GlobalContext* ctx ):
     Vector3Type( ctx, "vec3", new FloatType(ctx) )
    {}
};

class Vector4FloatType: public Vector4Type
{
public:
    Vector4FloatType( GlobalContext* ctx ):
     Vector4Type( ctx, "vec4", new FloatType(ctx) )
    {}
};


// matricial types
class Matrix4x4Type: public MatricialType
{
public:
    
    Matrix4x4Type( GlobalContext* ctx, const std::string& name, Type* type ):
     MatricialType( ctx, type, 4, 4 )
    {}
};

class Matrix3x4Type: public MatricialType
{
public:
    
    Matrix3x4Type( GlobalContext* ctx, const std::string& name, Type* type ):
     MatricialType( ctx, type, 3, 4 )
    {}
};

class Matrix4x3Type: public MatricialType
{
public:
    
    Matrix4x3Type( GlobalContext* ctx, const std::string& name, Type* type ):
     MatricialType( ctx, type, 4, 3 )
    {}
};

class Matrix3x3Type: public MatricialType
{
public:
    
    Matrix3x3Type( GlobalContext* ctx, const std::string& name, Type* type ):
     MatricialType( ctx, type, 3, 3 )
    {}
};

//Realisations
class Matrix4x4FloatType: public Matrix4x4Type
{
public:
    
   Matrix4x4FloatType( GlobalContext* ctx ):
    Matrix4x4Type( ctx, "matrix", new FloatType(ctx) )
   {}
};

class Matrix3x4FloatType: public Matrix3x4Type
{
public:
    
   Matrix3x4FloatType( GlobalContext* ctx ):
     Matrix3x4Type( ctx, "matrix3x4", new FloatType(ctx) )
    {}
};

class Matrix4x3FloatType: public Matrix4x3Type
{
public:
    
   Matrix4x3FloatType( GlobalContext* ctx ):
     Matrix4x3Type( ctx, "matrix4x3", new FloatType(ctx) )
    {}
};

class Matrix3x3FloatType: public Matrix3x3Type
{
public:
    
   Matrix3x3FloatType( GlobalContext* ctx ):
     Matrix3x3Type( ctx, "matrix3x3", new FloatType(ctx) )
    {}
};

#endif // __SC_MATRICIALTYPES_HPP__