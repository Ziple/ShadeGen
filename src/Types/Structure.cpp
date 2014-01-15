#include <Types/Structure.hpp>

std::string Structure::DeclarationString( const PrintingContext& pctx ) const
{
    std::string tabs = pctx.Tabs();
    
    std::string ret = tabs + "struct " + GetName() + "\n" + tabs + "{";
        
    for( size_t i = 0; i < myFields.size(); i++ )
    {
        ret += "\n    " + tabs + myFields[i].fieldType->GetName() + " " + myFields[i].fieldName + ";";
    }
    
    ret += "\n" + tabs + "};\n";
    return ret;
}