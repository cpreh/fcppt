//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_CONTAINS_V_HPP_INCLUDED
#define FCPPT_MPL_LIST_CONTAINS_V_HPP_INCLUDED

#include <fcppt/mpl/list/contains.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep

namespace fcppt::mpl::list
{
/**
\brief Checks if a list contains an element.
\ingroup fcpptmpl
\see fcppt::mpl::list::contains
*/
template <fcppt::mpl::list::object_concept List, typename E>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool contains_v = fcppt::mpl::list::contains<List,E>::value;
}

#endif
