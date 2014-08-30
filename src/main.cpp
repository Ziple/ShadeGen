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
#include <memory>

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
	std::shared_ptr<GlobalContext> ctx = std::make_shared<GlobalContext>();
    Type* uintT = ctx->GetTypeByName( "uint" );
    
    std::vector<StructureField> fields;

	StructureField t;
	t.fieldName = "x";
	t.fieldType = uintT;

    StructureField tt;
	tt.fieldName = "y";
	tt.fieldType = uintT;

    fields.push_back( t );
    fields.push_back( tt );
	Structure* str = new Structure(ctx.get(), "SS", fields);
    ctx->DeclareType( str );
    
    Variable* x = new Variable( ctx.get(), "x", uintT );
	Operator* xx = new Power(ctx.get(), x, new Constant(ctx.get(), 2.0));
	Operator* y = new Variable(ctx.get(), "y", uintT);
	Operator* yy = new Power(ctx.get(), y, new Constant(ctx.get(), 2.0));
	Operator* xxpyy = new Addition(ctx.get(), xx, yy);
	Operator* inv = new Inverse(ctx.get(), xxpyy);
	Instruction* retInv = new Return(ctx.get(), inv);
    std::vector<Operator*> conds;
    std::vector<InstructionList*> blocks;
    
	conds.push_back(new Constant(ctx.get(), 2.0));
	blocks.push_back(new InstructionList(ctx.get(), retInv));
    
	Instruction* ifElseBlock = new IfElseBlock(ctx.get(), conds, blocks, 0);
    std::vector<Instruction*> ins;
    ins.push_back( ifElseBlock );
	InstructionList* insl = new InstructionList(ctx.get(), ins);
	Function* f = new Function(ctx.get(), "f", insl);
    
    std::cout<<"Unsimplified original function:\n"<<ctx->ToString()<<std::endl;
    
    GlobalContext* sctx = ctx->Simplify();

    std::cout<<"Simplified function:\n"<<sctx->ToString()<<std::endl;
    
    dumpToFile( "Original.hlsl", ctx->ToString() );
    dumpToFile( "Simplified.hlsl", sctx->ToString() );
    delete sctx;
    return 0;
}
