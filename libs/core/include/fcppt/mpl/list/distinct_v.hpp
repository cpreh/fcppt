//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_DISTINCT_V_HPP_INCLUDED
#define FCPPT_MPL_LIST_DISTINCT_V_HPP_INCLUDED

#include <fcppt/mpl/list/distinct.hpp>
#include <fcppt/mpl/list/object_concept.hpp>

namespace fcppt::mpl::list
{
/**
\brief Checks if all elements of a list are pairwise disjoint.
\ingroup fcpptmpl
\see fcppt::mpl::list::distinct
*/
template<fcppt::mpl::list::object_concept List>
constexpr inline bool distinct_v = fcppt::mpl::list::distinct<List>::value;
}

#endif
