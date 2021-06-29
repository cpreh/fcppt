//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_FROM_HPP_INCLUDED
#define FCPPT_MPL_LIST_FROM_HPP_INCLUDED

#include <fcppt/mpl/list/object.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename Type>
struct from;

template<template<typename...> class Arg, typename... Types>
struct from<Arg<Types...>>
{
  using type = fcppt::mpl::list::object<Types...>;
};
}

template<typename Type>
using from = typename fcppt::mpl::list::detail::from<Type>::type;

}

#endif
