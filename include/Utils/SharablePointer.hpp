#ifndef __SC_SHARABLEPOINTER_HPP__
#define __SC_SHARABLEPOINTER_HPP__

#include <memory>

template< typename T >
class Sharable
{
public:

	typedef std::shared_ptr<T> Ptr;

};

#endif /* __SC_SHARABLEPOINTER_HPP__ */