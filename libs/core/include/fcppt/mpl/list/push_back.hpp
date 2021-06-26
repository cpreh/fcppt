//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_PUSH_BACK_HPP_INCLUDED
#define FCPPT_MPL_LIST_PUSH_BACK_HPP_INCLUDED

#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/object_concept.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename L, typename T>
struct push_back;

template<typename... E, typename T>
struct push_back<fcppt::mpl::list::object<E...>, T>
{
  using type = fcppt::mpl::list::object<E..., T>;
};
}

template<fcppt::mpl::list::object_concept List, typename T>
using push_back = typename fcppt::mpl::list::detail::push_back<List,T>::type;
}

#endif
