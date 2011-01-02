//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_TWOPI_HPP_INCLUDED
#define FCPPT_MATH_TWOPI_HPP_INCLUDED

#include <fcppt/math/pi.hpp>

namespace fcppt
{
namespace math
{

/// Returns 2*pi for type T
/**
 * @tparam T must be a floating point type
*/
template<
	typename T
>
inline
T
twopi()
{
	return static_cast<T>(2) * pi<T>();
}

}
}

#endif
