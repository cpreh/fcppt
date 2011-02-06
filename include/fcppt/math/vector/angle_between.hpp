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
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <cmath>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Calculates the relative angle between two vectors
/**
 * @tparam T must be a floating point type
 * The behaviour is undefined if length(_from - _to) == 0
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
