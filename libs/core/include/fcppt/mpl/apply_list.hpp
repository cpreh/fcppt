//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_APPLY_LIST_HPP_INCLUDED
#define FCPPT_MPL_APPLY_LIST_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/lambda_fwd.hpp>
#include <fcppt/mpl/list_concept.hpp>
#include <fcppt/mpl/list_fwd.hpp>

namespace fcppt::mpl
{
namespace detail
{
template<typename L, typename Args>
struct apply_list;

template<template<typename...> class L, typename... Args>
struct apply_list<fcppt::mpl::lambda<L>,fcppt::mpl::list<Args...>>
{
  using type = fcppt::mpl::apply<fcppt::mpl::lambda<L>,Args...>;
};
}

template<fcppt::mpl::lambda_concept Lambda, fcppt::mpl::list_concept Args>
using apply_list = typename fcppt::mpl::detail::apply_list<Lambda,Args>::type;
}

#endif
