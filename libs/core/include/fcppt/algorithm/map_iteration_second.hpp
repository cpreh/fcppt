//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_MAP_ITERATION_SECOND_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_ITERATION_SECOND_HPP_INCLUDED

#include <fcppt/algorithm/map_iteration.hpp>
#include <fcppt/type_traits/value_type.hpp>

namespace fcppt::algorithm
{
/**
\brief Iterates over a map with the possibility of erasing elements, passing
second.

\ingroup fcpptalgorithm

Iterates over \a _map, applying \a _update_action to the mapped object of each
element. If \a _update_action returns #fcppt::algorithm::update_action::remove, the element is
removed from the map.

\tparam Map A map-like container.

\tparam UpdateAction A function callable as
<code>fcppt::algorithm::update_action (Map::mapped_type)</code>.
*/
template <typename Map, typename UpdateAction>
void map_iteration_second(Map &_map, UpdateAction const &_update_action)
{
  auto const wrapper([&_update_action](fcppt::type_traits::value_type<Map> &_element) {
    return _update_action(_element.second);
  });

  fcppt::algorithm::map_iteration(_map, wrapper);
}

}

#endif
