//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_KEYS_HPP_INCLUDED
#define FCPPT_MPL_MAP_KEYS_HPP_INCLUDED

#include <fcppt/mpl/map/element_concept.hpp>
#include <fcppt/mpl/map/element_key.hpp>
#include <fcppt/mpl/map/object_concept.hpp>
#include <fcppt/mpl/map/object_fwd.hpp>
#include <fcppt/mpl/set/object_fwd.hpp>

namespace fcppt::mpl::map
{
namespace detail
{
template<typename Map>
struct keys;
template<fcppt::mpl::map::element_concept... Elements>
struct keys<fcppt::mpl::map::object<Elements...>>
{
  using type = fcppt::mpl::set::object<fcppt::mpl::map::element_key<Elements>...>;
};
}
/**
\brief They keys of a map as a set.
\ingroup fcpptmpl
Let <code>Map = map::object<element<K_1,V_1>,...,element<K_n,V_n>></code>.
Then the result is
\code
set::object<K_1,...,K_n>
\endcode
*/
template<fcppt::mpl::map::object_concept Map>
using keys = typename fcppt::mpl::map::detail::keys<Map>::type;
}

#endif
