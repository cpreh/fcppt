//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_EXCLUDE_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_EXCLUDE_IMPL_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/exclude_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/operators/not.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Parser, typename Exclude>
fcppt::parse::exclude<Parser, Exclude>::exclude(Parser &&_parser, Exclude &&_exclude)
    : parser_{std::move(_parser)}, exclude_{std::move(_exclude)}
{
}

template <typename Parser, typename Exclude>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::exclude<Parser, Exclude>::result_type>
fcppt::parse::exclude<Parser, Exclude>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  auto const parser{!fcppt::make_cref(this->exclude_) >> fcppt::make_cref(this->parser_)};

  return parser.parse(_state, _skipper);
}

#endif
