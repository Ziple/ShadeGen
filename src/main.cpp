#include <Intrinsics/Addition.hpp>
#include <Intrinsics/Substraction.hpp>
#include <Intrinsics/Multiplication.hpp>
#include <Intrinsics/Division.hpp>
#include <Intrinsics/Inverse.hpp>
#include <Variable.hpp>
#include <Constant.hpp>
#include <GlobalContext.hpp>
#include <Intrinsics/Power.hpp>
#include <Function.hpp>
#include <FlowControl/FunctionCall.hpp>
#include <FlowControl/IfElseBlock.hpp>
#include <FlowControl/Return.hpp>
#include <Instructions/InstructionList.hpp>

#include <Types/ScalarTypes.hpp>
#include <Types/Structure.hpp>

#include <string>
#include <iostream>
#include <fstream>

void dumpToFile( const std::string& filename, const std::string& content )
{
    std::ofstream f;
    f.open( filename.c_str(), std::ofstream::out );
    
    if( f.is_open() )
        f<<content;
    f.close();
}

int main( int argc, char** argv )
{
    GlobalContext* ctx = new GlobalContext();
    GlobalContext* sctx = new GlobalContext();
    
    Type* uintT = ctx->GetTypeByName( "uint" );
    
    std::vector<StructureField> fields;
    fields.push_back( { uintT, "x" } );
    fields.push_back( { uintT, "y" } );
    Structure* str = new Structure( ctx, "SS", fields );
    ctx->DeclareType( str );
    
    Variable* x = new Variable( ctx, "x" );
    Operator* xx = new Power( ctx, x, new Constant(ctx, 2.0) );
    Operator* y = new Variable( ctx, "y" );
    Operator* yy = new Power( ctx, y, new Constant(ctx, 2.0) );
    Operator* xxpyy = new Addition( ctx, xx, yy );
    Operator* inv = new Inverse( ctx, xxpyy );
    Instruction* retInv = new Return( ctx, inv );
    std::vector<Operator*> conds;
    std::vector<Instruction*> blocks;
    
    conds.push_back( new Constant( ctx, 2.0 ) );
    blocks.push_back( retInv );
    
    Instruction* ifElseBlock = new IfElseBlock( ctx, conds, blocks, 0 );
    std::vector<Instruction*> ins;
    ins.push_back( ifElseBlock );
    InstructionList* insl = new InstructionList( ctx, ins );
    Function* f = new Function( ctx, "f", insl );
    
    std::cout<<"Unsimplified original function:\n"<<ctx->ToString()<<std::endl;
    Operator* sf = f->Simplified(sctx);
    std::cout<<"Simplified function:\n"<<sctx->ToString()<<std::endl;
    
    dumpToFile( "Original.hlsl", ctx->ToString() );
    dumpToFile( "Simplified.hlsl", sctx->ToString() );
    delete ctx;
    return 0;
}
