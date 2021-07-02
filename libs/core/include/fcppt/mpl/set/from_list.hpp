//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_FROM_LIST_HPP_INCLUDED
#define FCPPT_MPL_SET_FROM_LIST_HPP_INCLUDED

#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/set/object.hpp>

namespace fcppt::mpl::set
{
namespace detail
{
template<typename List>
struct from_list;

template<typename... Types>
struct from_list<fcppt::mpl::list::object<Types...>>
{
  using type = fcppt::mpl::set::object<Types...>;
};
}

template <fcppt::mpl::list::object_concept List>
using from_list = typename fcppt::mpl::set::detail::from_list<List>::type;
}

#endif
