//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_BASIC_CHAR_SET_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_BASIC_CHAR_SET_IMPL_HPP_INCLUDED

#include <fcppt/output_to_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/container/contains.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/get_char_error.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/detail/expected.hpp>
#include <fcppt/parse/skipper/basic_char_set_decl.hpp>
#include <fcppt/parse/skipper/make_failure.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/parse/skipper/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::skipper::basic_char_set<Ch>::basic_char_set(std::initializer_list<Ch> const &_inits)
    : basic_char_set(char_set_type{_inits})
{
}

template <typename Ch>
fcppt::parse::skipper::basic_char_set<Ch>::basic_char_set(char_set_type &&_chars)
    : chars_{std::move(_chars)}
{
}

template <typename Ch>
fcppt::parse::skipper::result<Ch> fcppt::parse::skipper::basic_char_set<Ch>::skip(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state) const
{
  return fcppt::either::bind(fcppt::parse::get_char_error(_state), [_state, this](Ch const _ch) {
    return fcppt::container::contains(this->chars_, _ch)
               ? fcppt::parse::skipper::make_success<Ch>()
               : fcppt::parse::skipper::make_failure(fcppt::parse::detail::expected(
                     fcppt::parse::get_position(_state),
                     fcppt::output_to_string<std::basic_string<Ch>>(
                         fcppt::container::output(this->chars_)),
                     _ch));
  });
}

template <typename Ch>
typename fcppt::parse::skipper::basic_char_set<Ch>::char_set_type const &
fcppt::parse::skipper::basic_char_set<Ch>::chars() const
{
  return this->chars_;
}

#endif
