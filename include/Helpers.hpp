#ifndef __HELPERS_HPP__
#define __HELPERS_HPP__

#include <string>
#include <sstream>

template< typename T >
std::string to_string( const T& i )
{
    std::ostringstream oss;
    oss << i;
    return oss.str();
}

#endif // __HELPERS_HPP__