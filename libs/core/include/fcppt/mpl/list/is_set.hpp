//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_IS_SET_HPP_INCLUDED
#define FCPPT_MPL_LIST_IS_SET_HPP_INCLUDED

#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/size.hpp>
#include <fcppt/mpl/set/from_list_relaxed.hpp>
#include <fcppt/mpl/set/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
/**
\brief Checks if a list forms a set.
\ingroup fcpptmpl
*/
template <fcppt::mpl::list::object_concept List>
using is_set = std::is_same<
    fcppt::mpl::list::size<List>,
    fcppt::mpl::set::size<fcppt::mpl::set::from_list_relaxed<List>>>;
}

#endif
