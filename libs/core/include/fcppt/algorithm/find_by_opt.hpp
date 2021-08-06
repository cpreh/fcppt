//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_FIND_BY_OPT_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_BY_OPT_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Optionally finds an element and transforms it.

Returns the first element in \a _range for which \a _function does not return
an empty optional, if there is any. Otherwise, returns the empty optional.

\ingroup fcpptalgorithm

\tparam Function A function callable as <code>fcppt::optional::object<Result>
(V)</code> for every type <code>V</code> in \a Range.
*/
template <typename Result, typename Range, typename Function>
inline fcppt::optional::object<Result> find_by_opt(Range &&_range, Function const &_function)
{
  return fcppt::algorithm::fold_break(
      _range,
      fcppt::optional::object<Result>{},
      [&_function](auto &&_element, fcppt::optional::object<Result> &&_state)
      {
        return _state.has_value() ? std::make_pair(fcppt::loop::break_, std::move(_state))
                                  : std::make_pair(fcppt::loop::continue_, _function(_element));
      });
}

}

#endif
