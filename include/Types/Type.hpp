#ifndef __SC_TYPE_HPP__
#define __SC_TYPE_HPP__

#include <Utils/SharablePointer.hpp>

#include <GlobalContext.hpp>
#include <PrintingContext.hpp>

#include <string>

class Type : public Sharable<Type>
{
public:
    
    Type( GlobalContext* ctx,
          const std::string& name ):
     myCtx( ctx ),
     myTypeName( name )
    {
        ctx->RegisterType( this );
    }
    
    virtual ~Type();

    virtual Type* Clone( GlobalContext* nctx ) const = 0;
    
    const std::string& GetName() const { return myTypeName; }

    virtual const std::string& GetReducedName() const { return myTypeName; }

    virtual bool IsKnownType() const {return true;}
    
    virtual bool IsError() const {return false;}
    
    virtual bool IsVoid() const {return false;}
    
    virtual bool IsStructure() const {return false;}
    
    virtual bool IsScalar() const {return false;}
    
    virtual bool IsMatricial() const {return false;}
    
    virtual std::string DeclarationString( const PrintingContext& pctx  = PrintingContext() ) const;
    
protected:
    
    GlobalContext* myCtx;
    std::string myTypeName;
};


class VoidType: public Type
{
public:
    
    VoidType( GlobalContext* ctx ):
     Type( ctx, "void" )
    {}

    Type* Clone( GlobalContext* nctx ) const { return new VoidType( nctx ); }
    
    bool IsVoid() const {return true;}
};

class UnknownType: public Type
{
public:
    
    UnknownType( GlobalContext* ctx ):
        Type( ctx, "unknown" )
    {}
    
    Type* Clone( GlobalContext* nctx ) const { return new UnknownType( nctx ); }

    bool IsKnownType() const {return false;}
};

class ErrorType: public Type
{
public:
    
    ErrorType( GlobalContext* ctx, const std::string& errstr ):
     Type( ctx, "err" ),
     myErrorString( errstr )
    {}
    
    Type* Clone( GlobalContext* nctx ) const { return new ErrorType( nctx, myErrorString ); }

    bool IsError() const {return true;}
    
    const std::string& GetErrorString() const {return myErrorString;}
    
protected:
    
    std::string myErrorString;
};

#endif // __SC_TYPE_HPP__