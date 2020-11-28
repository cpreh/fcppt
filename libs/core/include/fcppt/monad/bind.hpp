//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MONAD_BIND_HPP_INCLUDED
#define FCPPT_MONAD_BIND_HPP_INCLUDED

#include <fcppt/move_if_rvalue_type.hpp>
#include <fcppt/monad/inner_type.hpp>
#include <fcppt/monad/instance_fwd.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace monad
{
/**
\brief Monadic bind.

\ingroup fcpptmonad
*/
template <typename Arg, typename Function>
inline std::invoke_result_t<
    Function,
    fcppt::move_if_rvalue_type<
        Arg,
        fcppt::monad::inner_type<fcppt::type_traits::remove_cv_ref_t<Arg>>>>
bind(Arg &&_arg, Function const &_function)
{
  return fcppt::monad::instance<fcppt::type_traits::remove_cv_ref_t<Arg>>::bind(
      std::forward<Arg>(_arg), _function);
}

}
}

#endif
