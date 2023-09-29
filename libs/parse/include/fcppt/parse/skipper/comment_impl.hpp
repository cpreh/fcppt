//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_COMMENT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_COMMENT_IMPL_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/skipper/any_impl.hpp>
#include <fcppt/parse/skipper/comment_decl.hpp> // IWYU pragma: export
#include <fcppt/parse/skipper/result.hpp>
#include <fcppt/parse/skipper/operators/not.hpp>
#include <fcppt/parse/skipper/operators/repetition.hpp>
#include <fcppt/parse/skipper/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Open, typename Close>
fcppt::parse::skipper::comment<Open, Close>::comment(Open &&_open, Close &&_close)
    : open_{std::move(_open)}, close_{std::move(_close)}
{
}

template <typename Open, typename Close>
template <typename Ch>
fcppt::parse::skipper::result<Ch> fcppt::parse::skipper::comment<Open, Close>::skip(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state) const
{
  auto const skipper{
      fcppt::make_cref(this->open_) >>
      *(!fcppt::make_cref(this->close_) >> fcppt::parse::skipper::any{}) >>
      fcppt::make_cref(this->close_)};

  return skipper.skip(_state);
}

#endif
