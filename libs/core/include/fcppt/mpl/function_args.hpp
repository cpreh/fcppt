//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_FUNCTION_ARGS_HPP_INCLUDED
#define FCPPT_MPL_FUNCTION_ARGS_HPP_INCLUDED

#include <fcppt/mpl/list/object_fwd.hpp>

namespace fcppt::mpl
{
namespace detail
{
template <typename Function>
struct function_args;

template <typename Ret, typename... Args>
struct function_args<Ret(Args...)>
{
  using type = fcppt::mpl::list::object<Args...>;
};
}

/**
\brief The argument types of a function as a list.
\ingroup fcpptmpl

\tparam Function Must be a function type.

TODO(concepts)
*/
template <typename Function>
using function_args = fcppt::mpl::detail::function_args<Function>::type;

}

#endif
