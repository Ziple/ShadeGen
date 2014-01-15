#ifndef __PRINTINGCONTEXT_HPP__
#define __PRINTINGCONTEXT_HPP__

#include <string>

struct PrintingContext
{
    PrintingContext(
        size_t tabLevel_ = 0,
        bool inlineWriting_ = true
    ):
     tabLevel( tabLevel_ ),
     inlineWriting( inlineWriting_ )
    {}
    
    std::string Tabs( size_t tabSize = 4 ) const
    {
        return std::string( tabLevel*tabSize, ' ');
    }
    
    PrintingContext AddTab() const
    {
        return PrintingContext( tabLevel + 1, inlineWriting );
    }
    
    PrintingContext RemoveTab() const
    {
        return PrintingContext( tabLevel > 0 ? tabLevel-1 : 0, inlineWriting );
    }
    
    PrintingContext InlineWriting() const
    {
        return PrintingContext( tabLevel, true );
    }
    
    PrintingContext OutOfLineWriting() const
    {
        return PrintingContext( tabLevel, false );
    }
    
    size_t tabLevel;
    bool inlineWriting;
};

#endif // __PRINTINGCONTEXT_HPP__