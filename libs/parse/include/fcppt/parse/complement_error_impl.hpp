//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_COMPLEMENT_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_COMPLEMENT_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/parse/complement_error_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::complement_error<Ch>::complement_error(
    pos_type const _pos, char_set_type &&_chars, got_type const _got)
    : pos_{_pos}, chars_{std::move(_chars)}, got_{_got.get()}
{
}

template <typename Ch>
typename fcppt::parse::complement_error<Ch>::pos_type
fcppt::parse::complement_error<Ch>::pos() const
{
  return this->pos_;
}

template <typename Ch>
typename fcppt::parse::complement_error<Ch>::char_set_type const &
fcppt::parse::complement_error<Ch>::chars() const
{
  return this->chars_;
}

template <typename Ch>
fcppt::optional::object<Ch> const &fcppt::parse::complement_error<Ch>::got() const
{
  return this->got_;
}

#endif
