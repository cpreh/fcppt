//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_CONTAINS_V_HPP_INCLUDED
#define FCPPT_MPL_SET_CONTAINS_V_HPP_INCLUDED

#include <fcppt/mpl/set/contains.hpp>
#include <fcppt/mpl/set/object_concept.hpp> // IWYU pragma: keep

namespace fcppt::mpl::set
{
/**
\brief Checks if a set contains an element.
\ingroup fcpptmpl
\see fcppt::mpl::set::contains
*/
template<fcppt::mpl::set::object_concept Set, typename Key>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool contains_v = fcppt::mpl::set::contains<Set,Key>::value;
}

#endif
