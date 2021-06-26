//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_ARG_HPP_INCLUDED
#define FCPPT_MPL_ARG_HPP_INCLUDED

#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/at.hpp>
#include <fcppt/mpl/list/object.hpp>
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
  template <typename... Args>
  using arg_apply =
      fcppt::mpl::list::at<fcppt::mpl::list::object<Args...>, fcppt::mpl::size_type<Arg>>;

  using type = fcppt::mpl::lambda<arg_apply>;
};
}

template<std::size_t Arg>
requires (Arg >= 1U)
using arg = typename fcppt::mpl::detail::arg<Arg - 1U>::type;
}

#endif
