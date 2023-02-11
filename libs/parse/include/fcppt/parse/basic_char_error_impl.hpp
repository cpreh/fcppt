//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_CHAR_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/parse/basic_char_error_decl.hpp>

template <typename Ch>
fcppt::parse::basic_char_error<Ch>::basic_char_error(pos_type const _pos) : pos_{_pos}
{
}

template <typename Ch>
typename fcppt::parse::basic_char_error<Ch>::pos_type
fcppt::parse::basic_char_error<Ch>::pos() const
{
  return this->pos_;
}

#endif
