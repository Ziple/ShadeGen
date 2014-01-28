#ifndef __RETURN_HPP__
#define __RETURN_HPP__

#include "../Instructions/Instruction.hpp"

class Return: public Instruction
{
public:
    
    Return( Context* ctx, Operator* op );
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );

    bool IsReturn() const { return true; }
};

#endif /* __RETURN_HPP__ */