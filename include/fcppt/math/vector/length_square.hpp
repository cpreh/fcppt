//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_LENGTH_SQUARE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_LENGTH_SQUARE_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/dot.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Calculates the square of the vector's length
/**
 * Equivalent to dot(@a v, @a v).
*/
template<
	typename T,
	typename N,
	typename S
>
typename basic<T, N, S>::value_type
length_square(
	basic<T, N, S> const &v
)
{
	return dot(v, v);
}

}
}
}

#endif
