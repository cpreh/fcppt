//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_INDICES_HPP_INCLUDED
#define FCPPT_MPL_LIST_INDICES_HPP_INCLUDED

#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/size.hpp>

namespace fcppt::mpl::list
{
/**
\brief Returns the positions of a list.
\ingroup fcpptmpl
If <code>List = list::object<L_1,...,L_n></code> then the result is
\code
list::object<size_type<0>,...,size_type<n-1>>
\endcode
*/
template<fcppt::mpl::list::object_concept List>
using indices = fcppt::mpl::list::interval<fcppt::mpl::size_type<0U>,fcppt::mpl::list::size<List>>;
}

#endif
