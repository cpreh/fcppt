//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_INITIAL_SIZE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INITIAL_SIZE_HPP_INCLUDED

#include <cstddef>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T,
	typename S
>
void
initial_size(
	T &t,
	S const size
)
{
	t.resize(size);
}

template<
	typename T,
	typename S,
	std::size_t N
>
void
initial_size(
	T (&)[N],
	S
)
{
}

}
}
}

#endif
