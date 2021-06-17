//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_ARG_HPP_INCLUDED
#define FCPPT_MPL_ARG_HPP_INCLUDED

#include <fcppt/mpl/at.hpp>
#include <fcppt/mpl/index.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
namespace detail
{
template<std::size_t Arg>
struct arg
{
  template<typename... Args>
  using arg_apply = fcppt::mpl::at<fcppt::mpl::list<Args...>,fcppt::mpl::index<Arg>>;

  using type = fcppt::mpl::lambda<arg_apply>;
};
}

template<std::size_t Arg>
using arg = typename fcppt::mpl::detail::arg<Arg>::type;
}

#endif
