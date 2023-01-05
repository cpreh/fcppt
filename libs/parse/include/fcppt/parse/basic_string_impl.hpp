//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_STRING_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_STRING_IMPL_HPP_INCLUDED

#include <fcppt/copy.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/parse/basic_char_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/basic_string_decl.hpp>
#include <fcppt/parse/basic_string_error_impl.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/expected_tag_fwd.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::basic_string<Ch>::basic_string(std::basic_string<Ch> &&_string)
    : string_{std::move(_string)}
{
}

template <typename Ch>
template <typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::basic_string<Ch>::result_type>
fcppt::parse::basic_string<Ch>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  fcppt::parse::basic_char<Ch> const impl{};

  fcppt::parse::position<Ch> const start_pos{fcppt::parse::get_position(_state)};

  for (Ch const elem : this->string_)
  {
    if (impl.parse(_state, _skipper) != fcppt::parse::make_success<Ch>(elem))
    {
      return fcppt::either::make_failure<result_type>(fcppt::parse::error<Ch>{
          fcppt::parse::error_variant<Ch>{fcppt::parse::basic_string_error<Ch>{
              start_pos,
              fcppt::make_strong_typedef<fcppt::parse::expected_tag>(fcppt::copy(this->string_))}},
          fcppt::parse::is_fatal{false}});
    }
  }

  return fcppt::parse::make_success<Ch>(fcppt::unit{});
}

#endif
