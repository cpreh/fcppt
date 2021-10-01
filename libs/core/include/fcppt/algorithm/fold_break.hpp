//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_FOLD_BREAK_HPP_INCLUDED
#define FCPPT_ALGORITHM_FOLD_BREAK_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/algorithm/loop_break.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Folds a range into a value, can break out early.

\ingroup fcpptalgorithm

Let <code> [e_1,...,e_n] </code> be the input range and <code>s_0 = _state</code>.

This function calls <code>(l_i, s_i) = _function(e_i,s_{i-1})</code> for <code>i = 1,...,x</code>
where <code>x <= n</code> is the largest number such that <code>l_j = loop::continue_</code>
for all <code>1 <= j < x</code>.

\tparam State Has to be movable

\tparam Function Must be callable as <code>std::pair<fcppt::loop, State>
(Range::value_type,State)</code>.
**/
template <typename Range, typename State, typename Function>
inline State fold_break(Range &&_range, State _state, Function _function)
{
  fcppt::algorithm::loop_break(
      std::forward<Range>(_range), [&_state, &_function](auto &&_fcppt_element) {
        std::pair<fcppt::loop, State> result{_function(_fcppt_element, std::move(_state))};

        _state = std::move(result.second);

        return result.first;
      });

  return _state;
}

}

#endif
