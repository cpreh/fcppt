//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_BACK_HPP_INCLUDED
#define FCPPT_MPL_LIST_BACK_HPP_INCLUDED

#include <fcppt/mpl/dec.hpp>
#include <fcppt/mpl/list/at.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/size.hpp>

namespace fcppt::mpl::list
{
/**
\brief The last element of a list.
\ingroup fcpptmpl
If <code>List = list::object<L_1,...,L_n></code> then the result is <code>L_n</code>.
*/
template<fcppt::mpl::list::object_concept List>
using back = fcppt::mpl::list::at<List,fcppt::mpl::dec<fcppt::mpl::list::size<List>>>;
}

#endif
