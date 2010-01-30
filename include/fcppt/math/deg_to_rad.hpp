//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DEG_TO_RAD_HPP_INCLUDED
#define FCPPT_MATH_DEG_TO_RAD_HPP_INCLUDED

#include <fcppt/math/pi.hpp>

namespace fcppt
{
namespace math
{

template<
	typename T
>
inline T
deg_to_rad(
	T const deg)
{
	return deg * pi<T>() / static_cast<T>(180);
}

}
}

#endif
