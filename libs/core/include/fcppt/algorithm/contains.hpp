//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_CONTAINS_HPP_INCLUDED
#define FCPPT_ALGORITHM_CONTAINS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <ranges>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Checks if a given value is inside a range.

\ingroup fcpptalgorithm

\tparam T Must be equality comparable to the range's value type.
*/
template <typename Range, typename T>
inline bool contains(Range const &_range, T const &_value)
{
  // NOLINTNEXTLINE(llvm-qualified-auto,readability-qualified-auto)
  auto const range_end{std::ranges::end(_range)};

  return ::std::find(std::ranges::begin(_range), range_end, _value) != range_end;
}

}

#endif
