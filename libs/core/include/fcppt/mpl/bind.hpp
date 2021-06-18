//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_BIND_HPP_INCLUDED
#define FCPPT_MPL_BIND_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/lambda.hpp>
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

template<fcppt::mpl::lambda_concept L, fcppt::mpl::lambda_concept ... Ls>
using bind = typename fcppt::mpl::detail::bind<L,Ls...>::type;
}

#endif
