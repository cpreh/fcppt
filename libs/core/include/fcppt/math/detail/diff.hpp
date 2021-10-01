//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_DIFF_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_DIFF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::detail
{
template <typename T>
inline std::enable_if_t<!std::is_unsigned<T>::value, T> diff(T const &a, T const &b)
{
  return std::abs(a - b);
}

template <typename T>
inline std::enable_if_t<std::is_unsigned<T>::value, T> diff(T const &a, T const &b)
{
  return std::min(a - b, b - a);
}

}

#endif
