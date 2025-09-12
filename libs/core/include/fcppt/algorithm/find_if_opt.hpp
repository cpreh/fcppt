//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_FIND_IF_OPT_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_IF_OPT_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <ranges>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Like <code>std::find_if</code> but returns an empty optional on failure.

\ingroup fcpptalgorithm

\tparam Comp Must be a function callable as <code>bool (Range::value_type)</code>.
*/
template <typename Range, typename Comp>
inline fcppt::optional::object<fcppt::container::to_iterator_type<std::remove_reference_t<Range>>>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
find_if_opt(Range &&_range, Comp const &_comp)
requires(std::ranges::input_range<std::remove_cvref_t<Range>>)
{
  using iterator_type = fcppt::container::to_iterator_type<std::remove_reference_t<Range>>;

  iterator_type const ret{::std::ranges::find_if(_range, _comp)};

  return fcppt::optional::make_if(ret != std::ranges::end(_range), [&ret]{ return ret; });
}

}

#endif
