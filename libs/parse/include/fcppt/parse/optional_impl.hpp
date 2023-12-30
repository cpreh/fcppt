//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_OPTIONAL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_OPTIONAL_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/optional/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/optional_decl.hpp> // IWYU pragma: export
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/set_position.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Parser>
fcppt::parse::optional<Parser>::optional(Parser &&_parser) : parser_{std::move(_parser)}
{
}

template <typename Parser>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::optional<Parser>::result_type>
fcppt::parse::optional<Parser>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

  return fcppt::either::match(
      fcppt::parse::deref(this->parser_).parse(_state, _skipper),
      [_state, pos](fcppt::parse::error<Ch> &&_error) {
        fcppt::parse::set_position(_state, pos);

        return _error.is_fatal() ? fcppt::either::make_failure<result_type>(std::move(_error))
                                 : fcppt::parse::make_success<Ch>(result_type{});
      },
      [](fcppt::parse::result_of<Parser> &&_result) {
        return fcppt::parse::make_success<Ch>(result_type{std::move(_result)});
      });
}

#endif
