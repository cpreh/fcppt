//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MONAD_DETAIL_DO_HPP_INCLUDED
#define FCPPT_MONAD_DETAIL_DO_HPP_INCLUDED

#include <fcppt/monad/bind.hpp>
#include <fcppt/tuple/invoke.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/tuple/push_back.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::monad::detail
{
template <typename Value, typename... Values>
inline std::remove_cvref_t<Value>
do_(Value &&_value, fcppt::tuple::object<Values...> const &)
{
  return std::forward<Value>(_value);
}

template <typename Value, typename... Values, typename Lambda, typename... Lambdas>
inline auto
do_(Value &&_value,
    fcppt::tuple::object<Values...> _values,
    Lambda const &_lambda,
    Lambdas const &..._lambdas)
{
  return fcppt::monad::bind(
      std::forward<Value>(_value),
      [&](auto const &_new_value)
      {
        auto const new_values{
            fcppt::tuple::push_back(std::forward<decltype(_values)>(_values), _new_value)};

        return fcppt::tuple::invoke(
            [&](auto &&..._args)
            { return fcppt::monad::detail::do_(_lambda(_args...), new_values, _lambdas...); },
            new_values);
      });
}
}

#endif
