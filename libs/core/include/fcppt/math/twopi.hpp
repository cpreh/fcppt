//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_TWOPI_HPP_INCLUDED
#define FCPPT_MATH_TWOPI_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/pi.hpp>

namespace fcppt
{
namespace math
{
/**
\brief Returns two Pi for type T
\ingroup fcpptmath
\tparam T Must be a floating point type
*/
template <typename T>
inline T twopi()
{
  return fcppt::literal<T>(2) * fcppt::math::pi<T>();
}

}
}

#endif
