//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_BINARY_SEARCH_HPP_INCLUDED
#define FCPPT_ALGORITHM_BINARY_SEARCH_HPP_INCLUDED

#include <fcppt/algorithm/equal_range.hpp>
#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/range/begin.hpp>
#include <fcppt/range/singular.hpp>
#include <fcppt/config/external_begin.hpp>
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
binary_search(Range &&_range, T const &_value)
{
  auto const result(fcppt::algorithm::equal_range(_range, _value));

  using result_type =
      fcppt::optional::object<fcppt::container::to_iterator_type<std::remove_reference_t<Range>>>;

  return fcppt::range::singular(result) ? result_type{fcppt::range::begin(result)} : result_type{};
}

}

#endif
