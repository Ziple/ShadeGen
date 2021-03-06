#ifndef __SC_FUNCTIONCALL_HPP__
#define __SC_FUNCTIONCALL_HPP__

#include "../Instructions/Instruction.hpp"

#include <Utils/SharablePointer.hpp>

#include <vector>

class Function;

class FunctionCall : public Instruction, public Sharable<FunctionCall>
{
public:
    
    FunctionCall( Context* ctx,
                  Function* called,
                  const std::vector<Operator*>& args
                );
    
    std::string ToString( const PrintingContext& pctx = PrintingContext() ) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );
    
protected:
    
    Function* myCalledFunction;
};

#endif /* __SC_FUNCTIONCALL_HPP__ */
