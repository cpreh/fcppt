//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_MAP_VALUES_REF_HPP_INCLUDED
#define FCPPT_CONTAINER_MAP_VALUES_REF_HPP_INCLUDED

#include <fcppt/is_reference.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/type_traits/value_type.hpp>

namespace fcppt
{
namespace container
{
/**
\brief Maps the mapped values of an associative container to a container of references.

\ingroup fcpptcontainer

\tparam Result A sequence container of <code>fcppt::reference<Map::mapped_type></code> or
<code>fcppt::reference<Map::mapped_type const></code>.

\tparam Map An associative container.
*/
template <typename Result, typename Map>
Result map_values_ref(Map &_map)
{
  static_assert(
      fcppt::is_reference<fcppt::type_traits::value_type<Result>>::value,
      "Result::value_type must be an fcppt::reference");

  return fcppt::algorithm::map<Result>(_map, [](auto &&_element) {
    return fcppt::type_traits::value_type<Result>{_element.second};
  });
}

}
}

#endif
