//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_FLIP_HPP_INCLUDED
#define FCPPT_MPL_MAP_FLIP_HPP_INCLUDED

#include <fcppt/mpl/map/element_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/map/element_fwd.hpp>
#include <fcppt/mpl/map/element_key.hpp>
#include <fcppt/mpl/map/element_value.hpp>
#include <fcppt/mpl/map/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/map/object_fwd.hpp>

namespace fcppt::mpl::map
{
namespace detail
{
template<typename T>
struct flip;

template<fcppt::mpl::map::element_concept... Elements>
struct flip<fcppt::mpl::map::object<Elements...>>
{
  using type = fcppt::mpl::map::object<fcppt::mpl::map::element<
      fcppt::mpl::map::element_value<Elements>,
      fcppt::mpl::map::element_key<Elements>>...>;
};
}
/**
\brief Flips the key-value pairs inside a map.
\ingroup fcpptmpl
Let <code>Map=map::object<element<K_1,V_1>,...,element<K_n,V_n>></code>.
Then the result is
\code
map::object<element<V_1,K_1>,...,element<V_n,K_n>>
\endcode
This only works if all the values <code>V_1,...,V_n</code> are pairwise disjoint.
*/
template <fcppt::mpl::map::object_concept Map>
using flip = fcppt::mpl::map::detail::flip<Map>::type;
}

#endif
