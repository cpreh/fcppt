//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OVERLOADED_DECL_HPP_INCLUDED
#define FCPPT_OVERLOADED_DECL_HPP_INCLUDED

#include <fcppt/overloaded_fwd.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace fcppt
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4626)
FCPPT_PP_DISABLE_VC_WARNING(5027)

/**
\brief Overloads multiple lambdas.

\ingroup fcpptvarious
*/
template <typename... Types>
struct overloaded // NOLINT(fuchsia-multiple-inheritance)
    : Types...
{
  template <typename... Args>
  explicit overloaded(Args &&...);

  using Types::operator()...;
};

FCPPT_PP_POP_WARNING

}

#endif
