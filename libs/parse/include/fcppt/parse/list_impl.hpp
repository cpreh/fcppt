//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_LIST_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_LIST_IMPL_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/convert_const_impl.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/list_decl.hpp> // IWYU pragma: export
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/separator_impl.hpp> // IWYU pragma: keep
#include <fcppt/parse/operators/alternative.hpp> // IWYU pragma: keep
#include <fcppt/parse/operators/sequence.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Start, typename Inner, typename Sep, typename End>
fcppt::parse::list<Start, Inner, Sep, End>::list(
    Start &&_start, Inner &&_inner, Sep &&_sep, End &&_end)
    : start_{std::move(_start)},
      separator_{std::move(_inner), std::move(_sep)},
      end_{std::move(_end)}
{
}

template <typename Start, typename Inner, typename Sep, typename End>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::list<Start, Inner, Sep, End>::result_type>
fcppt::parse::list<Start, Inner, Sep, End>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  auto const inner_parser(
      fcppt::make_cref(fcppt::parse::deref(this->start_)) >>
      (fcppt::parse::convert_const{fcppt::make_cref(this->end_), result_type{}} |
       (fcppt::make_cref(fcppt::parse::deref(this->separator_)) >> fcppt::make_cref(this->end_))));

  return inner_parser.parse(_state, _skipper);
}

#endif
