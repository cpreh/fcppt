//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_INSERT_HPP_INCLUDED
#define FCPPT_MPL_MAP_INSERT_HPP_INCLUDED

#include <fcppt/mpl/map/element.hpp>
#include <fcppt/mpl/map/has_key.hpp>
#include <fcppt/mpl/map/object.hpp>
#include <fcppt/mpl/map/object_concept.hpp> // IWYU pragma: keep

namespace fcppt::mpl::map
{
namespace detail
{
template<typename Map, typename Key, typename Value>
struct insert;

template<typename... Elements, typename Key, typename Value>
struct insert<fcppt::mpl::map::object<Elements...>,Key,Value>
{
  using type = fcppt::mpl::map::object<Elements...,fcppt::mpl::map::element<Key,Value>>;
};
}
/**
\brief Inserts a new element into a map.
\ingroup fcpptmpl
Let <code>Map = map::object<element<K_1,V_1>,...,element<K_n,V_n>></code>.
Then the result is
\code
map::object<element<K_1,V_1>,...,element<K_n,V_n>,element<Key,Value>>
\endcode
This only works if <code>Key</code> is not equal to any of the <code>K_1,...,K_n</code>.
*/
template<fcppt::mpl::map::object_concept Map, typename Key, typename Value>
requires (!fcppt::mpl::map::has_key<Map,Key>::value)
using insert = typename fcppt::mpl::map::detail::insert<Map,Key,Value>::type;
}

#endif
