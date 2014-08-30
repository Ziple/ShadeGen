#ifndef __SC_CONTEXT_HPP__
#define __SC_CONTEXT_HPP__

#include <Utils/SharablePointer.hpp>

#include "Function.hpp"
#include "Types/Type.hpp"

#include <string>
#include <vector>
#include <algorithm>

class Operator;
class Function;
class Type;

class Context : public Sharable<Context>
{
    public:
        
        Context( Context::Ptr parent = 0 );
        
        virtual ~Context();

        virtual Context::Ptr GetGlobalContext() { return myParent != 0 ? myParent->GetGlobalContext() : 0; }
        
        Type::Ptr GetTypeByName( const std::string& name );

        virtual void RegisterFunction( Function::Ptr fn );
        
        virtual void UnregisterFunction( Function::Ptr fn );
        
        void RegisterVariableName( const std::string& name );
        
        std::string GetFreeVariableName();
        
        bool IsVariableNameFree( const std::string& name );
        
    protected:
        
        Context::Ptr myParent;
        std::vector<Type::Ptr> myRegisteredTypes;
        std::vector<std::string> myRegisteredVariableNames;
};

#endif // __SC_CONTEXT_HPP__