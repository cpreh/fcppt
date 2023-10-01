//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_HAS_KEY_V_HPP_INCLUDED
#define FCPPT_MPL_MAP_HAS_KEY_V_HPP_INCLUDED

#include <fcppt/mpl/map/has_key.hpp>
#include <fcppt/mpl/map/object_concept.hpp>

namespace fcppt::mpl::map
{
/**
\brief Checks if a map contains a key.
\ingroup fcpptmpl
\see fcppt::mpl::map::has_key
*/
template<fcppt::mpl::map::object_concept Map, typename Key>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool has_key_v = fcppt::mpl::map::has_key<Map,Key>::value;
}

#endif
