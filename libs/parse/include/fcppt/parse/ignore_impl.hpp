//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_IGNORE_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_IGNORE_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/ignore_decl.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Parser>
fcppt::parse::ignore<Parser>::ignore(Parser &&_parser) : parser_{std::move(_parser)}
{
}

template <typename Parser>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::ignore<Parser>::result_type>
fcppt::parse::ignore<Parser>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  return fcppt::either::map(
      fcppt::parse::deref(this->parser_).parse(_state, _skipper),
      [](fcppt::parse::result_of<Parser> &&) { return fcppt::unit{}; });
}

#endif
