//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_REL_ANGLE_HPP_INCLUDED
#define FCPPT_MATH_IS_REL_ANGLE_HPP_INCLUDED

#include <fcppt/math/pi.hpp>
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
	bool
>::type
is_rel_angle(
	T const a
)
{
	return
		a >= -pi<T>()
		&& a <= pi<T>();
}

}
}

#endif
