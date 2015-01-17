//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_LENGTH_SQUARE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_LENGTH_SQUARE_HPP_INCLUDED

#include <fcppt/math/vector/dot.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculate the square of the vector's length
\ingroup fcpptmathvector
\tparam T The vector's <code>value_type</code>
\tparam N The vector's dimension type
\tparam S The vector's storage type
\param v The vector to calculate the length for.

This is equivalent to <code>dot(v,v)</code>.

\note
If you just want the length, use fcppt::math::vector::length

\see
fcppt::math::vector::length
*/
template<
	typename T,
	typename N,
	typename S
>
typename object<T, N, S>::value_type
length_square(
	object<T, N, S> const &v
)
{
	return dot(v, v);
}

}
}
}

#endif
