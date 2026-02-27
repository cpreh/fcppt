//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_STRING_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_STRING_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/parse/basic_string_error_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::basic_string_error<Ch>::basic_string_error(
    // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
    pos_type const _pos, expected_type &&_expected)
    : pos_{_pos}, expected_{std::move(_expected.get())}
{
}

template <typename Ch>
fcppt::parse::basic_string_error<Ch>::pos_type
fcppt::parse::basic_string_error<Ch>::pos() const
{
  return this->pos_;
}

template <typename Ch>
fcppt::parse::basic_string_error<Ch>::string_type const &
fcppt::parse::basic_string_error<Ch>::expected() const
{
  return this->expected_;
}

#endif
