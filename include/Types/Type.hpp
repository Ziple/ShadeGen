#ifndef __SC_TYPE_HPP__
#define __SC_TYPE_HPP__

#include <GlobalContext.hpp>
#include <PrintingContext.hpp>

#include <string>

class Type
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
    
    const std::string& GetName() const { return myTypeName; }
    
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
    
    bool IsVoid() const {return true;}
};

class ErrorType: public Type
{
public:
    
    ErrorType( GlobalContext* ctx, const std::string& errstr ):
     Type( ctx, "err" ),
     myErrorString( errstr )
    {}
    
    bool IsError() const {return true;}
    
    const std::string& GetErrorString() const {return myErrorString;}
    
protected:
    
    std::string myErrorString;
};

#endif // __SC_TYPE_HPP__