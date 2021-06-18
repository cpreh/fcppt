//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_PUSH_BACK_HPP_INCLUDED
#define FCPPT_MPL_PUSH_BACK_HPP_INCLUDED

#include <fcppt/mpl/list_concept.hpp>
#include <fcppt/mpl/list.hpp>

namespace fcppt::mpl
{
namespace detail
{
template<typename L, typename T>
struct push_back;

template<typename... E, typename T>
struct push_back<fcppt::mpl::list<E...>, T>
{
  using type = fcppt::mpl::list<E..., T>;
};
}

template<fcppt::mpl::list_concept List, typename T>
using push_back = typename fcppt::mpl::detail::push_back<List,T>::type;
}

#endif
