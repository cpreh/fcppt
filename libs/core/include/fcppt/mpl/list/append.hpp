//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_APPEND_HPP_INCLUDED
#define FCPPT_MPL_LIST_APPEND_HPP_INCLUDED

#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/object_fwd.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template <typename List1, typename List2>
struct append;

template <typename... Es1, typename... Es2>
struct append<fcppt::mpl::list::object<Es1...>,fcppt::mpl::list::object<Es2...>>
{
  using type = fcppt::mpl::list::object<Es1..., Es2...>;
};
}
/**
\brief Appends two lists.
\ingroup fcpptmpl
If <code>List1 = list::object<L_1,...,L_n></code> and <code>List2 = list::object<R_1,...,R_m></code>
then the result is
\code
list::object<L_1,...,L_n,R_1,...,R_m>
\endcode
*/
template <fcppt::mpl::list::object_concept List1, fcppt::mpl::list::object_concept List2>
using append = fcppt::mpl::list::detail::append<List1,List2>::type;
}

#endif
