//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_POP_BACK_HPP_INCLUDED
#define FCPPT_MPL_LIST_POP_BACK_HPP_INCLUDED

#include <fcppt/mpl/list/empty.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/mpl/list/push_back.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename List, typename Rest>
struct pop_back;

template<typename List, typename Rest>
struct pop_back<List,fcppt::mpl::list::object<Rest>>
{
  using type = List;
};

template<typename List, typename R, typename... Rest>
struct pop_back<List, fcppt::mpl::list::object<R, Rest...>>
{
  using type = typename fcppt::mpl::list::detail::
      pop_back<fcppt::mpl::list::push_back<List, R>, fcppt::mpl::list::object<Rest...>>::type;
};

}
template<fcppt::mpl::list::object_concept List>
requires (!fcppt::mpl::list::empty<List>::value)
using pop_back = typename fcppt::mpl::list::detail::pop_back<fcppt::mpl::list::object<>,List>::type;

}

#endif
