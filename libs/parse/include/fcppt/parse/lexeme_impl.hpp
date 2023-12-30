//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_LEXEME_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_LEXEME_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/lexeme_decl.hpp> // IWYU pragma: export
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Parser>
fcppt::parse::lexeme<Parser>::lexeme(Parser &&_parser) : parser_{std::move(_parser)}
{
}

template <typename Parser>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::lexeme<Parser>::result_type>
fcppt::parse::lexeme<Parser>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &) const
{
  return fcppt::parse::deref(this->parser_).parse(_state, fcppt::parse::skipper::epsilon{});
}

#endif
