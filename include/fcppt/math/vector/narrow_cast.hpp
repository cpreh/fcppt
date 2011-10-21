//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_NARROW_CAST_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_NARROW_CAST_HPP_INCLUDED

#include <fcppt/math/detail/narrow_cast.hpp>
#include <fcppt/math/vector/basic_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/// Converts a vector into a vector with fewer elements
/**
 * @tparam Dest must be a vector type with fewer elements.
*/
template<
	typename Dest,
	typename T,
	typename N,
	typename S
>
Dest const
narrow_cast(
	basic<T, N, S> const &src
)
{
	return
		math::detail::narrow_cast<
			Dest
		>(
			src
		);
}

}
}
}

#endif
