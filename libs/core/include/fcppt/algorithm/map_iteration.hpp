//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_MAP_ITERATION_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_ITERATION_HPP_INCLUDED

#include <fcppt/algorithm/update_action.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace fcppt::algorithm
{
/**
\brief Iterates over a map with the possibility of erasing elements.

\ingroup fcpptalgorithm

Iterates over \a _map, applying \a _update_action to each element. If \a
_update_action returns #fcppt::algorithm::update_action::remove,
the element is deleted from the map.

\tparam Map A map-like container.

\tparam UpdateAction A function callable as
<code>fcppt::algorithm::update_action (Map::value_type)</code>.
*/
template <typename Map, typename UpdateAction>
void map_iteration(Map &_map, UpdateAction const &_update_action)
{
  for (auto it(_map.begin()), next(it); it != _map.end(); it = next)
  {
    ++next;

    FCPPT_PP_PUSH_WARNING
    FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
    switch (_update_action(*it))
    {
    case fcppt::algorithm::update_action::remove:
      _map.erase(it);
      break;
    case fcppt::algorithm::update_action::keep:
      break;
    }
    FCPPT_PP_POP_WARNING
  }
}

}

#endif
