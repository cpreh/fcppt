//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/detail/structure_cast.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Converts a vector into a different vector of the same dimension using static_cast
template<
	typename Dest,
	typename T,
	typename N,
	typename S
>
Dest const
structure_cast(
	basic<T, N, S> const &src
)
{
	return math::detail::structure_cast<
		Dest
	>(
		src
	);

}

}
}
}

#endif
