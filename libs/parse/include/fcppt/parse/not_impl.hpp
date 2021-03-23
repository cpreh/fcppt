//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_NOT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_NOT_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/not_decl.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/set_position.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Parser>
fcppt::parse::not_<Parser>::not_(Parser &&_parser) : parser_{std::move(_parser)}
{
}

template <typename Parser>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::not_<Parser>::result_type>
fcppt::parse::not_<Parser>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

  bool const has_value{fcppt::parse::deref(this->parser_).parse(_state, _skipper).has_success()};

  fcppt::parse::set_position(_state, pos);

  return has_value ? fcppt::either::make_failure<result_type>(fcppt::parse::error<Ch>{
                         std::basic_string<Ch>{FCPPT_STRING_LITERAL(Ch, "NOT")}})
                   : fcppt::parse::make_success<Ch>(fcppt::unit{});
}

#endif
