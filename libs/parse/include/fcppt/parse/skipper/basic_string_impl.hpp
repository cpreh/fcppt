//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_BASIC_STRING_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_BASIC_STRING_IMPL_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/parse/basic_string_error_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/expected_tag_fwd.hpp>
#include <fcppt/parse/get_char.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/skipper/basic_string_decl.hpp>
#include <fcppt/parse/skipper/make_failure.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/parse/skipper/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::skipper::basic_string<Ch>::basic_string(std::basic_string<Ch> &&_string)
    : string_{std::move(_string)}
{
}

template <typename Ch>
fcppt::parse::skipper::result<Ch>
fcppt::parse::skipper::basic_string<Ch>::skip(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state) const
{
  fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

  for (Ch const elem : this->string_)
  {
    if (fcppt::parse::get_char(_state) != fcppt::optional::make(elem))
    {
      return fcppt::parse::skipper::make_failure(fcppt::parse::error<Ch>{
          fcppt::parse::error_variant<Ch>{fcppt::parse::basic_string_error<Ch>{
              pos, fcppt::make_strong_typedef<fcppt::parse::expected_tag>(this->string_)}},
          fcppt::parse::is_fatal{false}});
    }
  }

  return fcppt::parse::skipper::make_success<Ch>();
}

#endif
