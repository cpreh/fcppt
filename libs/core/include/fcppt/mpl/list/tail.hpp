//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_TAIL_HPP_INCLUDED
#define FCPPT_MPL_LIST_TAIL_HPP_INCLUDED

#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/object_fwd.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename List>
struct tail;
template<typename Head, typename... Tail>
struct tail<fcppt::mpl::list::object<Head,Tail...>>
{
  using type = fcppt::mpl::list::object<Tail...>;
};
}
/**
\brief Removes the first element of a list.
\ingroup fcpptmpl
If <code>List = list::object<L_1,...,L_n></code>,
where <code>n >= 1</code>, then the result is
\code
list::object<L_2,...,L_n>
\endcode
*/
template<fcppt::mpl::list::object_concept List>
using tail = fcppt::mpl::list::detail::tail<List>::type;
}

#endif
