//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_FIND_IF_OPT_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_IF_OPT_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/range/begin.hpp>
#include <fcppt/range/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
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
{
  using iterator_type = fcppt::container::to_iterator_type<std::remove_reference_t<Range>>;

  using result_type = fcppt::optional::object<iterator_type>;

  iterator_type const end{fcppt::range::end(_range)};

  iterator_type const ret(::std::find_if(fcppt::range::begin(_range), end, _comp));

  return ret == end ? result_type() : result_type(ret);
}

}

#endif
