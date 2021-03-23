//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_REPETITION_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_REPETITION_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/loop.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/set_position.hpp>
#include <fcppt/parse/skipper/make_failure.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/parse/skipper/repetition_decl.hpp>
#include <fcppt/parse/skipper/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Parser>
fcppt::parse::skipper::repetition<Parser>::repetition(Parser &&_parser)
    : parser_{std::move(_parser)}
{
}

template <typename Parser>
template <typename Ch>
fcppt::parse::skipper::result<Ch> fcppt::parse::skipper::repetition<Parser>::skip(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state) const
{
  fcppt::parse::position<Ch> pos{fcppt::parse::get_position(_state)};

  fcppt::parse::error<Ch> error{fcppt::either::loop(
      [this, _state] { return fcppt::parse::deref(this->parser_).skip(_state); },
      [_state, &pos](fcppt::either::no_error) { pos = fcppt::parse::get_position(_state); })};

  fcppt::parse::set_position(_state, pos);

  return error.is_fatal() ? fcppt::parse::skipper::make_failure(std::move(error))
                          : fcppt::parse::skipper::make_success<Ch>();
}

#endif
