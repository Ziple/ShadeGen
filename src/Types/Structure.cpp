#include <Types/Structure.hpp>

Type* Structure::Clone( GlobalContext* nctx ) const
{
    std::vector<StructureField> nfields;

    for( size_t i = 0; i < myFields.size(); i++ )
    {
        StructureField field;
        field.fieldName = myFields[i].fieldName;
        field.fieldType = myFields[i].fieldType->Clone( nctx );
        nfields.push_back( field );
    }

    return new Structure( nctx, myTypeName, nfields );
}

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