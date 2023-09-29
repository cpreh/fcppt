//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_CUSTOM_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_CUSTOM_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/parse/custom_error_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::custom_error<Ch>::custom_error(pos_type const _pos, string_type &&_message)
    : pos_{_pos}, message_{std::move(_message)}
{
}

template <typename Ch>
typename fcppt::parse::custom_error<Ch>::pos_type
fcppt::parse::custom_error<Ch>::pos() const
{
  return this->pos_;
}

template <typename Ch>
typename fcppt::parse::custom_error<Ch>::string_type const &
fcppt::parse::custom_error<Ch>::message() const
{
  return this->message_;
}

#endif
