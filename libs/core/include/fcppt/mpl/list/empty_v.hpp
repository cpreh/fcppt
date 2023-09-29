//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_EMPTY_V_HPP_INCLUDED
#define FCPPT_MPL_LIST_EMPTY_V_HPP_INCLUDED

#include <fcppt/mpl/list/empty.hpp>
#include <fcppt/mpl/list/object_concept.hpp>

namespace fcppt::mpl::list
{
/**
\brief Checks if a list is empty.
\ingroup fcpptmpl
\see fcppt::mpl::list::empty
*/
template<fcppt::mpl::list::object_concept List>
constexpr inline bool empty_v = fcppt::mpl::list::empty<List>::value;
}

#endif
