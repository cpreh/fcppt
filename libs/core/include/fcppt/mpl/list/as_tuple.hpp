//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_AS_TUPLE_HPP_INCLUDED
#define FCPPT_MPL_LIST_AS_TUPLE_HPP_INCLUDED

#include <fcppt/mpl/list/as.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/tuple/object_fwd.hpp>

namespace fcppt::mpl::list
{
/**
\brief Converts a list to a tuple.
If <code>List=list::object<L_1,...,L_n></code> then the result is
<code>fcppt::tuple::object<L_1,...,L_n></code>.
*/
template<fcppt::mpl::list::object_concept List>
using as_tuple = fcppt::mpl::list::as<fcppt::tuple::object, List>;
}

#endif
