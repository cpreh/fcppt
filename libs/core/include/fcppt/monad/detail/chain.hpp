//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MONAD_DETAIL_CHAIN_HPP_INCLUDED
#define FCPPT_MONAD_DETAIL_CHAIN_HPP_INCLUDED

#include <fcppt/monad/bind.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace monad
{
namespace detail
{
template <typename Value>
inline std::remove_cvref_t<Value> chain(Value &&_value)
{
  return std::forward<Value>(_value);
}

template <typename Value, typename Lambda, typename... Lambdas>
inline auto chain(Value &&_value, Lambda const &_lambda, Lambdas const &..._lambdas)
{
  return fcppt::monad::detail::chain(
      fcppt::monad::bind(std::forward<Value>(_value), _lambda), _lambdas...);
}

}
}
}

#endif
