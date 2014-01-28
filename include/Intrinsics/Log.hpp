#ifndef __SC_LOG_HPP__
#define __SC_LOG_HPP__

#include "UnaryOperator.hpp"

class Log: public UnaryOperator
{
public:
    Log( Context* ctx, Operator* op );
    
    std::string ToString(const PrintingContext& pctx = PrintingContext()) const;
    
    Operator* Simplified( Context* nctx, TypeCorrespondanceTable& correspondanceTable );
};

#endif // __SC_LOG_HPP__ 
