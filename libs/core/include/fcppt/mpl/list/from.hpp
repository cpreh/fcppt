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

/**
\brief Converts a template type to a list.
\ingroup fcpptmpl
If <code>Type = T<L_1, ..., L_n></code> then the result is <code>list::object<L_1,...,L_n></code>.
*/
template<typename Type>
using from = fcppt::mpl::list::detail::from<Type>::type;

}

#endif
