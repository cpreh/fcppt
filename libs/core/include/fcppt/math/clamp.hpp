//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_CLAMP_HPP_INCLUDED
#define FCPPT_MATH_CLAMP_HPP_INCLUDED

#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math
{
/**
\brief Clamps a value into a range.

\ingroup fcpptmath
*/
template <typename T>
fcppt::optional::object<T> clamp(T const &_value, T const &_vmin, T const &_vmax)
{
  return fcppt::optional::make_if(
      _vmin <= _vmax,
      [&_value, &_vmin, &_vmax] { return std::max(std::min(_value, _vmax), _vmin); });
}
}

#endif
