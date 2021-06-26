//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_KEYS_UNIQUE_HPP_INCLUDED
#define FCPPT_MPL_MAP_KEYS_UNIQUE_HPP_INCLUDED

#include <fcppt/mpl/list/distinct.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/map/element_concept.hpp>
#include <fcppt/mpl/map/element_key.hpp>

namespace fcppt::mpl::map
{
template <fcppt::mpl::map::element_concept... Args>
using keys_unique =
    fcppt::mpl::list::distinct<fcppt::mpl::list::object<fcppt::mpl::map::element_key<Args>...>>;
}

#endif
