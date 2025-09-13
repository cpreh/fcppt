//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_FOLD_HPP_INCLUDED
#define FCPPT_ALGORITHM_FOLD_HPP_INCLUDED

#include <fcppt/algorithm/loop.hpp>
#include <fcppt/config/external_begin.hpp>
#include <concepts>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Folds a range into a value.

\ingroup fcpptalgorithm

Like <code>fold_left</code> in a functional programming language, this function
starts with \a _state as <code>cur_state</code>, and calls <code> cur_state =
_function(element, cur_state)</code> for every element of \a _range.

\tparam Function Must be callable as <code>State (T,State)</code> for every type <code>T</code> in \a Range.
**/
template <typename Range, typename State, typename Function>
inline State fold(Range &&_range, State _state, Function _function)
requires(std::movable<State>)
{
  fcppt::algorithm::loop(std::forward<Range>(_range), [&_state, &_function](auto &&_fcppt_element) {
    _state = _function(std::forward<decltype(_fcppt_element)>(_fcppt_element), std::move(_state));
  });

  return _state;
}

}

#endif
