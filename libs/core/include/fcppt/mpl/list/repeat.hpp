//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_REPEAT_HPP_INCLUDED
#define FCPPT_MPL_LIST_REPEAT_HPP_INCLUDED

#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/size_type_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/mpl/list/map.hpp>

namespace fcppt::mpl::list
{
/**
\brief Creates a list that consists of n elements that are all the same.
\ingroup fcpptmpl
Let <code>S = fcppt::mpl::size_type<n></code>.
Then the result is
\code
list::object<T_1,...,T_n>
\endcode
where <code>T_1 = ... = T_n = T</code>.
*/
template <typename T, fcppt::mpl::size_type_concept S>
using repeat = fcppt::mpl::list::
    map<fcppt::mpl::list::interval<fcppt::mpl::size_type<0U>, S>, fcppt::mpl::constant<T>>;
}

#endif
