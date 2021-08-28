//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_WITH_LOCATION_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_WITH_LOCATION_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/basic_stream_impl.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/location.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/with_location_decl.hpp>
#include <fcppt/parse/detail/sequence_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Parser>
fcppt::parse::with_location<Parser>::with_location(Parser &&_parser) : parser_{std::move(_parser)}
{
}

template <typename Parser>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::with_location<Parser>::result_type>
fcppt::parse::with_location<Parser>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  fcppt::optional::object<fcppt::parse::location> const location{_state->get_position().location()};

  return fcppt::either::map(
    fcppt::parse::deref(this->parser_).parse(_state,_skipper),
    [&location](fcppt::parse::result_of<Parser> &&_inner)
    {
      return fcppt::parse::detail::sequence_result(location,std::move(_inner));
    });
}

#endif
