//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_UNIQUE_HPP_INCLUDED
#define FCPPT_MPL_LIST_UNIQUE_HPP_INCLUDED

#include <fcppt/mpl/set/from_list_relaxed.hpp>
#include <fcppt/mpl/set/to_list.hpp>

namespace fcppt::mpl::list
{
/**
\brief Removes duplicates from a list.
\ingroup fcpptrecord
*/
template <fcppt::mpl::list::object_concept List>
using unique = fcppt::mpl::set::to_list<fcppt::mpl::set::from_list_relaxed<List>>;

}

#endif
