//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_OPERATORS_REPETITION_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_OPERATORS_REPETITION_HPP_INCLUDED

#include <fcppt/parse/skipper/is_valid_argument.hpp>
#include <fcppt/parse/skipper/repetition_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::skipper
{
/**
\brief Creates an #fcppt::parse::skipper::repetition.
\ingroup fcpptparse
*/
template <typename Parser>
fcppt::parse::skipper::repetition<std::remove_cvref_t<Parser>> operator*(Parser &&_parser)
  requires(fcppt::parse::skipper::is_valid_argument<Parser>::value)
{
  return fcppt::parse::skipper::repetition<std::remove_cvref_t<Parser>>{
      std::forward<Parser>(_parser)};
}
}

#endif
