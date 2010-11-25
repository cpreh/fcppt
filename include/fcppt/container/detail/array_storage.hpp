//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_ARRAY_STORAGE_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_ARRAY_STORAGE_HPP_INCLUDED

#include <cstddef>

namespace fcppt
{
namespace container
{
namespace detail
{

template<
	typename T,
	std::size_t N
>
struct array_storage
{
	typedef T type[N];
};

template<
	typename T
>
struct array_storage<
	T,
	0
>
{
	typedef T *type;
};

}
}
}

#endif
