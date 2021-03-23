//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MONAD_DO_HPP_INCLUDED
#define FCPPT_MONAD_DO_HPP_INCLUDED

#include <fcppt/monad/detail/do.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace monad
{
/**
\brief Do-notation for monads.

\ingroup fcpptmonad
*/
template <typename Value, typename... Lambdas>
auto do_(Value &&_value, Lambdas const &..._lambdas)
{
  return fcppt::monad::detail::do_(std::forward<Value>(_value), fcppt::tuple::object<>{}, _lambdas...);
}

}
}

#endif
