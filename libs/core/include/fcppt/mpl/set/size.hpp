//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_SIZE_HPP_INCLUDED
#define FCPPT_MPL_SET_SIZE_HPP_INCLUDED

#include <fcppt/mpl/list/size.hpp>
#include <fcppt/mpl/set/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/set/to_list.hpp>

namespace fcppt::mpl::set
{
/**
\brief The size of a set.
\ingroup fcpptmpl
If <code>Set = set::object<L_1,...,L_n></code>
then the result is
<code>fcppt::mpl::size_type<n></code>.
*/
template <fcppt::mpl::set::object_concept Set>
using size = fcppt::mpl::list::size<fcppt::mpl::set::to_list<Set>>;

}

#endif
