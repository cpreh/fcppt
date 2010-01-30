//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_RAD_TO_DEG_HPP_INCLUDED
#define FCPPT_MATH_RAD_TO_DEG_HPP_INCLUDED

#include <fcppt/math/pi.hpp>

namespace fcppt
{
namespace math
{

template<
	typename T
>
inline T
rad_to_deg(
	T const rad)
{
	return rad * static_cast<T>(180) / pi<T>();
}

}
}

#endif
