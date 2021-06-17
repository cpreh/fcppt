//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_CONSTANT_HPP_INCLUDED
#define FCPPT_MPL_CONSTANT_HPP_INCLUDED

#include <fcppt/mpl/lambda.hpp>

namespace fcppt::mpl
{
namespace detail
{
template<typename T>
struct constant
{
  template<typename... Args>
  using constant_apply = T;

  using type = fcppt::mpl::lambda<constant_apply>;
};
}

template<typename T>
using constant = typename fcppt::mpl::detail::constant<T>::type;
}

#endif

