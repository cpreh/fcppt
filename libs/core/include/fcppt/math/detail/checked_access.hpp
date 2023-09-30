//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::detail
{
template <fcppt::math::size_type N, typename T>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
inline fcppt::container::to_reference_type<std::remove_reference_t<T>> checked_access(T &&_value)
{
  using static_size = typename std::remove_reference_t<T>::static_size;

  static_assert(N < static_size::value, "Out of bounds access to a math type");

  return _value.get_unsafe(N);
}

}

#endif
