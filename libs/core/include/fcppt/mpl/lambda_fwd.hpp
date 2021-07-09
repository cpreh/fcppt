//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LAMBDA_FWD_HPP_INCLUDED
#define FCPPT_MPL_LAMBDA_FWD_HPP_INCLUDED

namespace fcppt::mpl
{
/**
\brief The lambda type.
\ingroup fcpptmpl

Every function <code>F</code> that is used by this library must be wrapped
inside a lambda.
*/
template<template<typename...> class F>
struct lambda;

}

#endif
