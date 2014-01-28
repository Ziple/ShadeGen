#ifndef __SC_STRUCTURE_HPP__
#define __SC_STRUCTURE_HPP__

#include "Type.hpp"

#include <vector>

struct StructureField
{
    Type* fieldType;
    std::string fieldName;
};

class Structure: public Type
{
public:
    
    Structure(
        GlobalContext* ctx,
        const std::string& name,
        const std::vector<StructureField>& fields
    ):
     Type( ctx, name ),
     myFields( fields )
    {}

    Type* Clone( GlobalContext* nctx ) const;
    
    bool IsStructure() const { return true; }
    
    const std::vector<StructureField>& GetFields() const {return myFields;}
    
    std::string DeclarationString( const PrintingContext& pctx  = PrintingContext() ) const;
    
protected:
    
    std::vector<StructureField> myFields;
};

#endif /* __SC_STRUCTURE_HPP__ */