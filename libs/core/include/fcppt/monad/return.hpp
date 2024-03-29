//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MONAD_RETURN_HPP_INCLUDED
#define FCPPT_MONAD_RETURN_HPP_INCLUDED

#include <fcppt/monad/constructor.hpp>
#include <fcppt/monad/instance_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::monad
{
/**
\brief Monadic return.

\ingroup fcpptmonad
*/
template <typename Type, typename Value>
fcppt::monad::constructor<Type, std::remove_cvref_t<Value>> return_(Value &&_value)
{
  return fcppt::monad::instance<Type>::return_(std::forward<Value>(_value));
}

}

#endif
