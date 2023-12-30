//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_BIND_HPP_INCLUDED
#define FCPPT_MPL_BIND_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/lambda_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/apply.hpp>
#include <fcppt/mpl/list/object.hpp>

namespace fcppt::mpl
{
namespace detail
{
template<typename L, typename... Ls>
struct bind;

template<template<typename...> class L, template<typename...> class... Ls>
struct bind<fcppt::mpl::lambda<L>,fcppt::mpl::lambda<Ls>...>
{
  template <typename Args>
  using bind_apply_list = fcppt::mpl::
      apply<fcppt::mpl::lambda<L>, fcppt::mpl::list::apply<fcppt::mpl::lambda<Ls>, Args>...>;

  template<typename... Args>
  using bind_apply = bind_apply_list<fcppt::mpl::list::object<Args...>>;
  //using bind_apply = L<Ls<Args...>...>;

  using type = fcppt::mpl::lambda<bind_apply>;
};
}

/**
\brief Function composition on multiple lambdas.
\ingroup fcpptmpl

Suppose that <code>L</code> holds a function <code>G</code> and
<code>Ls...</code> hold functions <code>Gs...</code>,
then <code>bind<L,Ls...></code> is a lambda that when called with arguments <code>Args...</code> it returns
\code
G<Gs<Args...>...>
\endcode
Formally, let <code>G</code> be of arity <code>k</code> and
<code>Gs... = G_1, ..., G_k</code> be of arity <code>m</code>.
Then <code>fcppt::mpl::bind<L,L_1,...,L_k></code> holds a function <code>F</code> of arity <code>m</code>,
such that <code>F<T_1,...,T_m> = G<G_1<T_1,...,T_m>,...,G_k<T_1,...,T_m>></code>.
*/
template<fcppt::mpl::lambda_concept L, fcppt::mpl::lambda_concept ... Ls>
using bind = typename fcppt::mpl::detail::bind<L,Ls...>::type;
}

#endif
