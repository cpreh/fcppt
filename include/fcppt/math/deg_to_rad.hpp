//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DEG_TO_RAD_HPP_INCLUDED
#define FCPPT_MATH_DEG_TO_RAD_HPP_INCLUDED

#include <fcppt/math/pi.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{

/// Transforms degeree into radians
/**
 * Equal to @a deg * PI / 180
*/
template<
	typename T
>
inline
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	T
>::type
deg_to_rad(
	T const deg
)
{
	return deg * pi<T>() / static_cast<T>(180);
}

}
}

#endif
