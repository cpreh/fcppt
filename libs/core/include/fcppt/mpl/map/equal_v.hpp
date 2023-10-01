//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_EQUAL_V_HPP_INCLUDED
#define FCPPT_MPL_MAP_EQUAL_V_HPP_INCLUDED

#include <fcppt/mpl/map/equal.hpp>
#include <fcppt/mpl/map/object_concept.hpp>

namespace fcppt::mpl::map
{
/**
\brief Checks if two maps are equal.
\ingroup fcpptmpl
\see fcppt::mpl::map::equal
*/
template <fcppt::mpl::map::object_concept Map1, fcppt::mpl::map::object_concept Map2>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool equal_v = fcppt::mpl::map::equal<Map1,Map2>::value;
}

#endif
