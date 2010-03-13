//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_ABS_ANGLE_TO_REL_HPP_INCLUDED
#define FCPPT_MATH_ABS_ANGLE_TO_REL_HPP_INCLUDED

#include <fcppt/math/mod.hpp>
#include <fcppt/math/is_rel_angle.hpp>
#include <fcppt/math/twopi.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>

namespace fcppt
{
namespace math
{

/// Transform an arbitrary angle into the range [-pi,pi]
/**
 * @tparam T The type must be a floating point type
*/
template<
	typename T
>
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	T
>::type
abs_angle_to_rel(
	T a
)
{
	a = mod(a, twopi<T>());

	if (is_rel_angle(a))
		return a;

	return a > 0
		? a - twopi<T>()
		: a + twopi<T>();
}

}
}

#endif
