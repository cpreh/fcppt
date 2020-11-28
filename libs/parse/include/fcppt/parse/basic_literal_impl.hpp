//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_LITERAL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_LITERAL_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/parse/basic_literal_decl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/char_impl.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/detail/expected.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::basic_literal<Ch>::basic_literal(Ch const _ch) : ch_{_ch}
{
}

template <typename Ch>
template <typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::basic_literal<Ch>::result_type>
fcppt::parse::basic_literal<Ch>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  fcppt::parse::basic_char<Ch> const parser{};

  return fcppt::either::bind(parser.parse(_state, _skipper), [_state, this](Ch const _ch) {
    return _ch == this->ch_
               ? fcppt::parse::make_success<Ch>(fcppt::unit{})
               : fcppt::either::make_failure<result_type>(fcppt::parse::detail::expected(
                     fcppt::parse::get_position(_state), std::basic_string<Ch>{this->ch_}, _ch));
  });
}

#endif
