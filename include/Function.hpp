#ifndef __SC_FUNCTION_HPP__
#define __SC_FUNCTION_HPP__

#include "Operator.hpp"
#include "Context.hpp"

#include <string>
#include <vector>

class Variable;
class InstructionList;

class Function: public Operator
{
public:
    
    Function( Context* ctx,
              const std::string& name,
              InstructionList* instructions );
    
    ~Function();
    
    const std::string& GetName() {return myName;}
    
    const Context& GetLocalContext() const { return myLocalContext; }
    
    Context& GetLocalContext() { return myLocalContext; }
    
    std::string ToString( const PrintingContext& pctx  = PrintingContext() ) const;
    
    Operator* Simplified( Context* nctx );
    
protected:
    
    Context myLocalContext;
    std::string myName;
};

#endif // __SC_FUNCTION_HPP__

