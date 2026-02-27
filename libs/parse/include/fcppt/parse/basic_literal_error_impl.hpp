//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_LITERAL_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_LITERAL_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/basic_literal_error_decl.hpp> // IWYU pragma: export

template <typename Ch>
fcppt::parse::basic_literal_error<Ch>::basic_literal_error(
    pos_type const _pos, expected_type const _expected, got_type const _got)
    : pos_{_pos}, expected_{_expected.get()}, got_{_got.get()}
{
}

template <typename Ch>
fcppt::parse::basic_literal_error<Ch>::pos_type
fcppt::parse::basic_literal_error<Ch>::pos() const
{
  return this->pos_;
}

template <typename Ch>
Ch fcppt::parse::basic_literal_error<Ch>::expected() const
{
  return this->expected_;
}

template <typename Ch>
fcppt::optional::object<Ch> const &fcppt::parse::basic_literal_error<Ch>::got() const
{
  return this->got_;
}

#endif
