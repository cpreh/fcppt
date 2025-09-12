//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_BINARY_SEARCH_HPP_INCLUDED
#define FCPPT_ALGORITHM_BINARY_SEARCH_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/range/singular.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <ranges>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Finds an element by binary search.

\ingroup fcpptalgorithm

If there is exactly one element that is uncomparable to \a _value, returns an
iterator to that element. Otherwise, returns the empty optional.

\tparam T Must be less-than comparable to the range's value type.
*/
template <typename Range, typename T>
fcppt::optional::object<fcppt::container::to_iterator_type<std::remove_reference_t<Range>>>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
binary_search(Range &&_range, T const &_value)
requires(std::ranges::input_range<std::remove_cvref_t<Range>>)
{
  auto const result{std::ranges::equal_range(_range, _value)};

  return fcppt::optional::make_if(
      fcppt::range::singular(result), [&result] { return std::ranges::begin(result); });
}

}

#endif
