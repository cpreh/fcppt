//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_INDEX_OF_HPP_INCLUDED
#define FCPPT_ALGORITHM_INDEX_OF_HPP_INCLUDED

#include <fcppt/algorithm/find_opt.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ranges>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Returns the index of the first element found in a sequence.

\ingroup fcpptalgorithm

Searches for \a _value in \a _range and returns the index of the first
occurrence if there is any, otherwise returns the empty optional.

\tparam Range A random access range.

\tparam T A type equality-comparable to the ranges's value type.
*/
template <typename Range, typename T>
inline fcppt::optional::object<std::ranges::range_size_t<Range>>
index_of(Range const &_range, T const &_value)
{
  // NOLINTNEXTLINE(llvm-qualified-auto,readability-qualified-auto)
  auto const beg{std::ranges::begin(_range)};

  return fcppt::optional::map(fcppt::algorithm::find_opt(_range, _value), [beg](auto const _it) {
    return fcppt::cast::to_unsigned(_it - beg);
  });
}

}

#endif
