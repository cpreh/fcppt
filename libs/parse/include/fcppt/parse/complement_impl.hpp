//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_COMPLEMENT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_COMPLEMENT_IMPL_HPP_INCLUDED

#include <fcppt/output_to_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/container/contains.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/parse/basic_char_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/complement_decl.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Parser>
fcppt::parse::complement<Parser>::complement(Parser &&_parser) : parser_{std::move(_parser)}
{
}

template <typename Parser>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::complement<Parser>::result_type>
fcppt::parse::complement<Parser>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  fcppt::parse::basic_char<Ch> const parser{};

  return fcppt::either::bind(parser.parse(_state, _skipper), [this](Ch const _result) {
    return fcppt::container::contains(fcppt::parse::deref(this->parser_).chars(), _result)
               ? fcppt::either::make_failure<result_type>(fcppt::parse::error<Ch>{
                     FCPPT_STRING_LITERAL(Ch, "Expected any char but {") +
                     fcppt::output_to_string<std::basic_string<Ch>>(
                         fcppt::container::output(fcppt::parse::deref(this->parser_).chars())) +
                     std::basic_string<Ch>{FCPPT_STRING_LITERAL(Ch, "}, got ")} + _result})
               : fcppt::parse::make_success<Ch>(_result);
  });
}

#endif
