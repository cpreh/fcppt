//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_BASIC_LITERAL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_BASIC_LITERAL_IMPL_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/basic_literal_error_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/expected_tag_fwd.hpp>
#include <fcppt/parse/get_char.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/got_tag_fwd.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/skipper/basic_literal_decl.hpp> // IWYU pragma: export
#include <fcppt/parse/skipper/make_failure.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/parse/skipper/result.hpp>

template <typename Ch>
fcppt::parse::skipper::basic_literal<Ch>::basic_literal(Ch const _ch) : ch_{_ch}
{
}

template <typename Ch>
fcppt::parse::skipper::result<Ch> fcppt::parse::skipper::basic_literal<Ch>::skip(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state) const
{
  fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

  fcppt::optional::object<Ch> const res{fcppt::parse::get_char(_state)};

  return res == fcppt::optional::make(this->ch_)
             ? fcppt::parse::skipper::make_success<Ch>()
             : fcppt::parse::skipper::make_failure(fcppt::parse::error<Ch>{
                   fcppt::parse::error_variant<Ch>{fcppt::parse::basic_literal_error<Ch>{
                       pos,
                       fcppt::make_strong_typedef<fcppt::parse::expected_tag>(this->ch_),
                       fcppt::make_strong_typedef<fcppt::parse::got_tag>(res)}},
                   fcppt::parse::is_fatal{false}});
}

#endif
