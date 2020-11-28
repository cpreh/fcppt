//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_NAMED_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_NAMED_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/either/map_failure.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/named_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch, typename Parser>
fcppt::parse::named<Ch, Parser>::named(Parser &&_parser, std::basic_string<Ch> &&_name)
    : parser_{std::move(_parser)}, name_{std::move(_name)}
{
}

template <typename Ch, typename Parser>
template <typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::named<Ch, Parser>::result_type>
fcppt::parse::named<Ch, Parser>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  return fcppt::either::map_failure(
      fcppt::parse::deref(this->parser_).parse(_state, _skipper),
      [this](fcppt::parse::error<Ch> && // TODO(philipp)
      ) { return fcppt::parse::error<Ch>{FCPPT_STRING_LITERAL(Ch, "Expected ") + this->name_}; });
}

#endif
