//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_ARRAY_LESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_LESS_HPP_INCLUDED

#include <fcppt/math/to_array.hpp>
#include <fcppt/math/to_array_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{
template <typename T>
inline bool array_less(T const &_a, T const &_b)
{
  fcppt::math::to_array_type<T> const array_a(fcppt::math::to_array(_a));

  fcppt::math::to_array_type<T> const array_b(fcppt::math::to_array(_b));

  return std::lexicographical_compare(
      array_a.begin(), array_a.end(), array_b.begin(), array_b.end());
}

}
}
}

#endif
