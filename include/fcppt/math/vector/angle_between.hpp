//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ANGLE_BETWEEN_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ANGLE_BETWEEN_HPP_INCLUDED

#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/dot.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculates the angle between two floating point vectors
\ingroup fcpptmathvector
\tparam T The vector's <code>value_type</code>. Must be a floating point type.
\tparam N The vector's dimension type
\tparam S1 The first vector's storage type
\tparam S2 The first vector's storage type

If you want to calculate the angles between two vectors whose value type is not
a floating point type, see fcppt::math::vector::angle_between_cast.

\see fcppt::math::vector::angle_between_cast

\warning
The behaviour is undefined if \p _from or \p _to are very close to zero.
*/
template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	T
>::type
angle_between(
	basic<T, N, S1> const &_from,
	basic<T, N, S2> const &_to
)
{
	return
		std::acos(
			vector::dot(
				_from,
				_to
			)
			/
			(
			vector::length(
				_from) *
			vector::length(
				_to)
			)
		);
}

}
}
}

#endif
