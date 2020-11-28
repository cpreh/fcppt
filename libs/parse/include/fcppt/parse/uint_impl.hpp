//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_UINT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_UINT_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/make_lexeme.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/uint_decl.hpp>
#include <fcppt/parse/detail/basic_int_impl.hpp>
#include <fcppt/parse/skipper/run.hpp>

template <typename Type>
fcppt::parse::uint<Type>::uint() = default;

template <typename Type>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::uint<Type>::result_type>
fcppt::parse::uint<Type>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  auto const parser{fcppt::parse::make_lexeme(fcppt::parse::detail::basic_int<Type>{})};

  return fcppt::either::bind(
      fcppt::parse::skipper::run(_skipper, _state),
      [&parser, &_state, &_skipper](fcppt::unit) { return parser.parse(_state, _skipper); });
}

#endif
