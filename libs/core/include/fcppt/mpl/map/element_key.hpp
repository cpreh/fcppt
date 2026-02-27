//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_ELEMENT_KEY_HPP_INCLUDED
#define FCPPT_MPL_MAP_ELEMENT_KEY_HPP_INCLUDED

#include <fcppt/mpl/map/element_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/map/element_fwd.hpp>

namespace fcppt::mpl::map
{
namespace detail
{
template<typename Element>
struct element_key;

template<typename Key, typename Value>
struct element_key<fcppt::mpl::map::element<Key,Value>>
{
  using type = Key;
};
}

/**
\brief The key type of an element.
\ingroup fcpptmpl
Returns <code>K</code> if <code>Element=map::element<K,V></code>.
*/
template<fcppt::mpl::map::element_concept Element>
using element_key = fcppt::mpl::map::detail::element_key<Element>::type;

}

#endif
