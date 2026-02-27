//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_TYPED_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_TYPED_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/parse/typed_error_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::typed_error<Ch>::typed_error(
    // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
    pos_type const _pos, type_name_type &&_type_name, got_type &&_got)
    : pos_{_pos}, type_name_{std::move(_type_name.get())}, got_{std::move(_got.get())}
{
}

template <typename Ch>
fcppt::parse::typed_error<Ch>::pos_type fcppt::parse::typed_error<Ch>::pos() const
{
  return this->pos_;
}

template <typename Ch>
fcppt::parse::typed_error<Ch>::string_type const &
fcppt::parse::typed_error<Ch>::type_name() const
{
  return this->type_name_;
}

template <typename Ch>
fcppt::parse::typed_error<Ch>::string_type const &
fcppt::parse::typed_error<Ch>::got() const
{
  return this->got_;
}

#endif
