//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_AS_HPP_INCLUDED
#define FCPPT_MPL_LIST_AS_HPP_INCLUDED

#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/apply.hpp>
#include <fcppt/mpl/list/object_concept.hpp>

namespace fcppt::mpl::list
{
template<template<typename...> class Type, fcppt::mpl::list::object_concept List>
using as = fcppt::mpl::list::apply<fcppt::mpl::lambda<Type>,List>;
}

#endif
