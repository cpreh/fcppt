//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_FOLD_HPP_INCLUDED
#define FCPPT_MPL_LIST_FOLD_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/lambda_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/lambda_fwd.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
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
  using type = fcppt::mpl::list::detail::fold<
      fcppt::mpl::list::object<Es...>,
      fcppt::mpl::lambda<L>,
      fcppt::mpl::apply<fcppt::mpl::lambda<L>, E, V>>::type;
};
}

/**
\brief Folds a list.
\ingroup fcpptmpl

Let <code>List = list::object<L_1,...,L_n></code> and <code>L</code> hold a
function <code>F</code> of arity <code>2</code>.
Let <code>V_i = F<L_{i+1},V_{i+1}></code>
for <code>0 <= i < n</code> and <code>V_n = V</code>.
Then the result is <code>V_0</code>.
The calculations are
\code
V_0 = F<L_1,V_1>
V_1 = F<L_2,V_2>
...
V_{n-1} = F<L_n,V_n>
V_n = V
\endcode
Notice that if <code>n=0</code> then V_0 = V.
*/
template<fcppt::mpl::list::object_concept List, fcppt::mpl::lambda_concept L, typename V>
using fold = fcppt::mpl::list::detail::fold<List,L,V>::type;

}

#endif
