//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_RAD_TO_DEG_HPP_INCLUDED
#define FCPPT_MATH_RAD_TO_DEG_HPP_INCLUDED

#include <fcppt/math/pi.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{

/// Transforms radians into degree
/**
 * Equal to @a rad * 180 / PI
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
rad_to_deg(
	T const rad
)
{
	return rad * static_cast<T>(180) / pi<T>();
}

}
}

#endif
