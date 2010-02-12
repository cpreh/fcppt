//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_REL_ANGLE_TO_ABS_HPP_INCLUDED
#define FCPPT_MATH_REL_ANGLE_TO_ABS_HPP_INCLUDED

#include <fcppt/math/is_rel_angle.hpp>
#include <fcppt/math/almost_zero.hpp>
#include <fcppt/math/twopi.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/format.hpp>
#include <fcppt/text.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>

namespace fcppt
{
namespace math
{

template<
	typename T
>
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	T
>::type
rel_angle_to_abs(
	T const a
)
{
	if(!is_rel_angle(a))
		throw exception(
			(
				format(
					FCPPT_TEXT("math::rel_angle_to_abs: relative angle %1% out of range!")
				)
				% a
			).str()
		);

	if (almost_zero(a))
		return static_cast<T>(0);

	return a > static_cast<T>(0) ? a : twopi<T>()+a;
}

}
}

#endif
