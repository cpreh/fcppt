//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_SEQUENCE_ITERATION_HPP_INCLUDED
#define FCPPT_ALGORITHM_SEQUENCE_ITERATION_HPP_INCLUDED

#include <fcppt/algorithm/update_action.hpp>

namespace fcppt
{
namespace algorithm
{
/**
\brief Iterates over a sequence with the possibility of erasing elements.

\ingroup fcpptalgorithm

Iterates over \a _sequence, applying \a _update_action to each element. If \a
_update_action returns #fcppt::algorithm::update_action::remove,
the element is removed from the sequence.

\tparam UpdateAction A function callable as
<code>fcppt::algorithm::update_action (Sequence::value_type)</code>.
*/
template <typename Sequence, typename UpdateAction>
void sequence_iteration(Sequence &_sequence, UpdateAction const &_update_action)
{
  for (auto it(_sequence.begin()); it != _sequence.end();)
  {
    switch (_update_action(*it))
    {
    case fcppt::algorithm::update_action::remove:
      it = _sequence.erase(it // NOLINT(fuchsia-default-arguments-calls)
      );

      break;
    case fcppt::algorithm::update_action::keep:
      ++it;

      break;
    }
  }
}

}
}

#endif
