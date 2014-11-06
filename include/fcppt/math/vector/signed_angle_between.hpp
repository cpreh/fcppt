//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_SIGNED_ANGLE_BETWEEN_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_SIGNED_ANGLE_BETWEEN_HPP_INCLUDED

#include <fcppt/math/detail/has_size.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/atan2.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculates the signed angle between two 2D vectors
\ingroup fcpptmathvector
\tparam N The vector's dimension
\tparam T The vector's <code>value_type</code>. Must be a floating point type.
\tparam S1 The first vector's storage type
\tparam S2 The second vector's storage type
\param _from The first vector
\param _to The second vector

This just uses fcppt::math::vector::atan2 on the difference between the two
vectors.

If you want to calculate the angle between two vectors whose value type is not
a floating point type, see fcppt::math::vector::signed_angle_between_cast.

If you want to calculate the (unsigned) angle between two vectors of higher
dimensions, use fcppt::math::vector::angle_between or fcppt::math::vector::angle_between_cast.

\see fcppt::math::vector::signed_angle_between_cast
\see fcppt::math::vector::angle_between
\see fcppt::math::vector::angle_between_cast

\warning
Behaviour is undefined if \p _from and \p _to are nearly identical.
*/
template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
T
signed_angle_between(
	fcppt::math::vector::object<T, N, S1> const &_from,
	fcppt::math::vector::object<T, N, S2> const &_to
)
{
	static_assert(
		std::is_floating_point<
			T
		>::value
		&&
		fcppt::math::detail::has_size<
			N,
			2
		>::value,
		"signed_angle_between can only be used on 2D floating point vector types"
	);

	return
		fcppt::math::vector::atan2(
			_to
			- _from
		);
}

}
}
}

#endif
