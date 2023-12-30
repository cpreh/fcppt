//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_EMPTY_HPP_INCLUDED
#define FCPPT_MPL_LIST_EMPTY_HPP_INCLUDED

#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{

/**
\brief Checks if a list is empty.
\ingroup fcpptmpl
Let <code>List = list::object<L_1,...,L_n></code>. If <code>n = 0</code> then <code>std::true_type</code> is returned.
Otherwise, <code>std::false_type</code>is returned.
*/
template<fcppt::mpl::list::object_concept List>
using empty = std::is_same<fcppt::mpl::list::size<List>,fcppt::mpl::size_type<0U>>;

}

#endif
