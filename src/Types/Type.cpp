#include <Types/Type.hpp>

Type::~Type()
{
    // if the type is declared, we undeclare it first
    myCtx->UndeclareType( this );
    
    myCtx->UnregisterType( this );
}

std::string Type::DeclarationString( const PrintingContext& pctx ) const
{
    return "";
}