//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_OBJECT_FWD_HPP_INCLUDED
#define FCPPT_MPL_MAP_OBJECT_FWD_HPP_INCLUDED

#include <fcppt/mpl/map/element_concept.hpp>
#include <fcppt/mpl/map/keys_unique.hpp>

namespace fcppt::mpl::map
{
template <fcppt::mpl::map::element_concept... Args>
requires fcppt::mpl::map::keys_unique<Args...>::value
struct object;
}

#endif
