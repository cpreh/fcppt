//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_SEQUENCE_RESULT_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_SEQUENCE_RESULT_HPP_INCLUDED

#include <fcppt/unit.hpp>
#include <fcppt/parse/detail/combine_tuples.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::detail
{
inline fcppt::unit sequence_result(fcppt::unit, fcppt::unit) { return fcppt::unit{}; }

template <typename Left>
std::remove_cvref_t<Left> sequence_result(Left &&_left, fcppt::unit)
{
  return std::forward<Left>(_left);
}

template <typename Right>
std::remove_cvref_t<Right> sequence_result(fcppt::unit, Right &&_right)
{
  return std::forward<Right>(_right);
}

template <typename Left, typename Right>
auto sequence_result(Left &&_left, Right &&_right) -> decltype(
    fcppt::parse::detail::combine_tuples(std::forward<Left>(_left), std::forward<Right>(_right)))
{
  return fcppt::parse::detail::combine_tuples(
      std::forward<Left>(_left), std::forward<Right>(_right));
}

}

#endif
