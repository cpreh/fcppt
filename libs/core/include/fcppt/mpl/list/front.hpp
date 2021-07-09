//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_FRONT_HPP_INCLUDED
#define FCPPT_MPL_LIST_FRONT_HPP_INCLUDED

#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/object_fwd.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename List>
struct front;
template<typename Head, typename... Tail>
struct front<fcppt::mpl::list::object<Head,Tail...>>
{
  using type = Head;
};
}
/**
\brief The first element of a list.
\ingroup fcpptmpl
If <code>List = list::object<L_1,...,L_n></code> then the result is <code>L_1</code>.
*/
template<fcppt::mpl::list::object_concept List>
using front = typename fcppt::mpl::list::detail::front<List>::type;
}

#endif
