//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_FOLD_HPP_INCLUDED
#define FCPPT_MPL_FOLD_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/lambda_fwd.hpp>
#include <fcppt/mpl/list_concept.hpp>
#include <fcppt/mpl/list_fwd.hpp>

namespace fcppt::mpl
{
namespace detail
{
template<typename List, typename L, typename V>
struct fold;

template<template<typename...> class L, typename V>
struct fold<fcppt::mpl::list<>,fcppt::mpl::lambda<L>,V>
{
  using type = V;
};

template<typename E,typename... Es, template<typename...> class L, typename V>
struct fold<fcppt::mpl::list<E,Es...>,fcppt::mpl::lambda<L>,V>
{
  using type = typename fcppt::mpl::detail::fold<
      fcppt::mpl::list<Es...>,
      fcppt::mpl::lambda<L>,
      fcppt::mpl::apply<fcppt::mpl::lambda<L>, E, V>>::type;
};
}

template<fcppt::mpl::list_concept List, fcppt::mpl::lambda_concept L, typename V>
using fold = typename fcppt::mpl::detail::fold<List,L,V>::type;

}

#endif
