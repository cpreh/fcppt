//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_LITERAL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_LITERAL_IMPL_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/basic_literal_decl.hpp>
#include <fcppt/parse/basic_literal_error_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/expected_tag_fwd.hpp>
#include <fcppt/parse/get_char.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/got_tag_fwd.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/result.hpp>

template <typename Ch>
fcppt::parse::basic_literal<Ch>::basic_literal(Ch const _ch) : ch_{_ch}
{
}

template <typename Ch>
template <typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::basic_literal<Ch>::result_type>
fcppt::parse::basic_literal<Ch>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &) const
{
  fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

  fcppt::optional::object<Ch> const res{fcppt::parse::get_char(_state)};

  return res == fcppt::optional::make(this->ch_)
             ? fcppt::parse::make_success<Ch>(fcppt::unit{})
             : fcppt::either::make_failure<result_type>(fcppt::parse::error<Ch>{
                   fcppt::parse::error_variant<Ch>{fcppt::parse::basic_literal_error<Ch>{
                       pos,
                       fcppt::make_strong_typedef<fcppt::parse::expected_tag>(this->ch_),
                       fcppt::make_strong_typedef<fcppt::parse::got_tag>(res)}},
                   fcppt::parse::is_fatal{false}});
}

#endif
