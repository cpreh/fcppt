//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_APPLY_HPP_INCLUDED
#define FCPPT_MPL_APPLY_HPP_INCLUDED

#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/lambda_fwd.hpp>

namespace fcppt::mpl
{
namespace detail
{
template<typename L,typename... Args>
struct apply;

template<template<typename...> class T, typename... Args>
struct apply<fcppt::mpl::lambda<T>,Args...>
{
  using type = T<Args...>;
};
}

template<fcppt::mpl::lambda_concept L,typename... Args>
using apply = typename fcppt::mpl::detail::apply<L,Args...>::type;

}

#endif
