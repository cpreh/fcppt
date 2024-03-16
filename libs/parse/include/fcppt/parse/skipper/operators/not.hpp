//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_OPERATORS_NOT_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_OPERATORS_NOT_HPP_INCLUDED

#include <fcppt/parse/skipper/is_valid_argument.hpp>
#include <fcppt/parse/skipper/not_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::skipper
{
/**
\brief Creates an #fcppt::parse::skipper::not_ skipper.
\ingroup fcpptparse
*/
template <typename Skipper>
[[nodiscard]] inline fcppt::parse::skipper::not_<std::remove_cvref_t<Skipper>>
operator!(Skipper &&_skipper)
  requires(fcppt::parse::skipper::is_valid_argument<Skipper>::value)
{
  return fcppt::parse::skipper::not_<std::remove_cvref_t<Skipper>>{std::forward<Skipper>(_skipper)};
}
}

#endif
