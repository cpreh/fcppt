//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_UNIQUE_HPP_INCLUDED
#define FCPPT_MPL_SET_UNIQUE_HPP_INCLUDED

#include <fcppt/mpl/list/distinct.hpp>
#include <fcppt/mpl/list/object.hpp>

namespace fcppt::mpl::set
{
/**
\brief Checks if a variadic list is pairwise disjoint.
\ingroup fcpptmpl
*/
template <typename... Args>
using unique = fcppt::mpl::list::distinct<fcppt::mpl::list::object<Args...>>;
}

#endif
