//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_FOLD_HPP_INCLUDED
#define FCPPT_MPL_LIST_FOLD_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/lambda_fwd.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/object_fwd.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename List, typename L, typename V>
struct fold;

template<template<typename...> class L, typename V>
struct fold<fcppt::mpl::list::object<>,fcppt::mpl::lambda<L>,V>
{
  using type = V;
};

template<typename E,typename... Es, template<typename...> class L, typename V>
struct fold<fcppt::mpl::list::object<E,Es...>,fcppt::mpl::lambda<L>,V>
{
  using type = typename fcppt::mpl::list::detail::fold<
      fcppt::mpl::list::object<Es...>,
      fcppt::mpl::lambda<L>,
      fcppt::mpl::apply<fcppt::mpl::lambda<L>, E, V>>::type;
};
}

template<fcppt::mpl::list::object_concept List, fcppt::mpl::lambda_concept L, typename V>
using fold = typename fcppt::mpl::list::detail::fold<List,L,V>::type;

}

#endif
