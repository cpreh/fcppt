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

/**
\brief A lambda that returns an argument in a specific position.
\ingroup fcpptmpl

A lambda that returns the argument in position <code>Arg</code>.
Formally, for every integer <code>m >= Arg</code> it is a lambda that holds a function
<code>F_m</code> of arity <code>m</code>, such that <code>F_m<T_1,...,T_m> = T_Arg</code>.

\note Argument counting starts at <code>1</code> instead of <code>0</code>.
*/
template<std::size_t Arg>
requires (Arg >= 1U)
using arg = typename fcppt::mpl::detail::arg<Arg - 1U>::type;
}

#endif
