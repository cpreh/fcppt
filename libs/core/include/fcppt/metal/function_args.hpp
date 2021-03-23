//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_FUNCTION_ARGS_HPP_INCLUDED
#define FCPPT_METAL_FUNCTION_ARGS_HPP_INCLUDED

#include <fcppt/metal/detail/function_args.hpp>

namespace fcppt
{
namespace metal
{
/**
\brief The argument types of a function as a metal::list.

\ingroup fcpptmetal

\tparam Function Must be a function type.
*/
template <typename Function>
using function_args = typename fcppt::metal::detail::function_args<Function>::type;

}
}

#endif
