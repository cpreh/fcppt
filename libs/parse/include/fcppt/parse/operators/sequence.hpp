//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_OPERATORS_SEQUENCE_HPP_INCLUDED
#define FCPPT_PARSE_OPERATORS_SEQUENCE_HPP_INCLUDED

#include <fcppt/parse/is_valid_argument.hpp>
#include <fcppt/parse/sequence_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Creates an #fcppt::parse::sequence parser.
\ingroup fcpptparse
*/
template <typename Left, typename Right>
inline fcppt::parse::sequence<std::remove_cvref_t<Left>, std::remove_cvref_t<Right>>
operator>>(Left &&_left, Right &&_right)
  requires(std::conjunction_v<
           fcppt::parse::is_valid_argument<Left>,
           fcppt::parse::is_valid_argument<Right>>)
{
  return fcppt::parse::sequence<std::remove_cvref_t<Left>, std::remove_cvref_t<Right>>{
      std::forward<Left>(_left), std::forward<Right>(_right)};
}
}

#endif
