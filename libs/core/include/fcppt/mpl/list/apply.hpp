//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_APPLY_HPP_INCLUDED
#define FCPPT_MPL_LIST_APPLY_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/lambda_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/lambda_fwd.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/object_fwd.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename L, typename Args>
struct apply;

template<template<typename...> class L, typename... Args>
struct apply<fcppt::mpl::lambda<L>,fcppt::mpl::list::object<Args...>>
{
  using type = fcppt::mpl::apply<fcppt::mpl::lambda<L>,Args...>;
};
}

/**
\brief Calls a lambda using a list of arguments.
\ingroup fcpptmpl

If <code>L</code> holds a function <code>F</code> of arity n and <code>Args = list::object<A_1,...,A_n></code>,
then <code>F<A_1,...,A_n></code> is returned.
*/
template<fcppt::mpl::lambda_concept L, fcppt::mpl::list::object_concept Args>
using apply = typename fcppt::mpl::list::detail::apply<L,Args>::type;
}

#endif
