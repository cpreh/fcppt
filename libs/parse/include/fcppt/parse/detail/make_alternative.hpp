//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_MAKE_ALTERNATIVE_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_MAKE_ALTERNATIVE_HPP_INCLUDED

#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::detail
{
template <typename Result, typename Arg>
inline Result make_alternative(Arg &&_arg)
  requires(std::negation_v<fcppt::variant::is_object<Result>>)
{
  static_assert(std::is_same_v<std::remove_cvref_t<Arg>, Result>);

  return std::forward<Arg>(_arg);
}

template <typename Result, typename Arg>
Result make_alternative(Arg &&_arg)
  requires(std::conjunction_v<
           fcppt::variant::is_object<Result>,
           std::negation<fcppt::variant::is_object<std::remove_cvref_t<Arg>>>>)
{
  return Result{std::forward<Arg>(_arg)};
}

template <typename Result, typename Arg>
Result make_alternative(Arg &&_arg)
  requires(std::conjunction_v<
           fcppt::variant::is_object<Result>,
           fcppt::variant::is_object<std::remove_cvref_t<Arg>>>)
{
  return fcppt::variant::apply(
      [](auto &&_value) { return Result{std::forward<decltype(_value)>(_value)}; },
      std::forward<Arg>(_arg));
}
}

#endif
