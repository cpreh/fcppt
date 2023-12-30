//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_KEYS_UNIQUE_HPP_INCLUDED
#define FCPPT_MPL_MAP_KEYS_UNIQUE_HPP_INCLUDED

#include <fcppt/mpl/list/distinct.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/map/element_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/map/element_key.hpp>

namespace fcppt::mpl::map
{
/**
\brief Checks if the keys of elements are pairwise disjoint.
\ingroup fcpptmpl
Let <code>Args=element<K_1,V_1>,...,element<K_n,V_n></code>.
The result is <code>std::true_type</code> if all the keys <code>K_1,...,K_n</code> are pairwise disjoint.
Otherwise, it is <code>std::false_type</code>.
*/
template <fcppt::mpl::map::element_concept... Args>
using keys_unique =
    fcppt::mpl::list::distinct<fcppt::mpl::list::object<fcppt::mpl::map::element_key<Args>...>>;
}

#endif
