//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PARSE_STRING_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_STRING_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/parse/parse_stream_error_impl.hpp>
#include <fcppt/parse/parse_string_error_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::parse_string_error<Ch>::parse_string_error(
    fcppt::parse::parse_stream_error<Ch> &&_stream_error, optional_string &&_rest)
    : stream_error_{std::move(_stream_error)}, rest_{std::move(_rest)}
{
}

template <typename Ch>
fcppt::parse::parse_string_error<Ch>::parse_string_error(std::basic_string<Ch> &&_rest)
: stream_error_{}, rest_{std::move(_rest)}
{
}

template <typename Ch>
fcppt::parse::parse_string_error<Ch>::parse_string_error() : stream_error_{}, rest_{}
{
}

template <typename Ch>
typename fcppt::parse::parse_string_error<Ch>::optional_stream_error const &
fcppt::parse::parse_string_error<Ch>::stream_error() const
{
  return this->stream_error_;
}

template <typename Ch>
typename fcppt::parse::parse_string_error<Ch>::optional_string const &
fcppt::parse::parse_string_error<Ch>::rest() const
{
  return this->rest_;
}

#endif
