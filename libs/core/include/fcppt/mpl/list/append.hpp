//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_APPEND_HPP_INCLUDED
#define FCPPT_MPL_LIST_APPEND_HPP_INCLUDED

#include <fcppt/mpl/list/object_concept.hpp>
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
template <fcppt::mpl::list::object_concept List1, fcppt::mpl::list::object_concept List2>
using append = typename fcppt::mpl::list::detail::append<List1,List2>::type;
}

#endif
