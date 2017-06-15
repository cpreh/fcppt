//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_LENGTH_SQUARE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_LENGTH_SQUARE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
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

\param _vector The vector to calculate the length for.

\note
If you just want the length, use fcppt::math::vector::length

\see
fcppt::math::vector::length
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
inline
T
length_square(
	fcppt::math::vector::object<
		T,
		N,
		S
	> const &_vector
)
{
	return
		fcppt::math::vector::dot(
			_vector,
			_vector
		);
}

}
}
}

#endif
