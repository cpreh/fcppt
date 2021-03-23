//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MONAD_CHAIN_HPP_INCLUDED
#define FCPPT_MONAD_CHAIN_HPP_INCLUDED

#include <fcppt/monad/detail/chain.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace monad
{
/**
\brief Chains multiple bind calls.

\ingroup fcpptmonad

Let <code>Lambdas = l_1, ..., l_n</code>.
Calls <code>bind(... bind(bind(_value,_l1),l_2) ... ,l_n)</code>.
*/
template <typename Value, typename... Lambdas>
auto chain(Value &&_value, Lambdas const &..._lambdas)
{
  return fcppt::monad::detail::chain(std::forward<Value>(_value), _lambdas...);
}

}
}

#endif
