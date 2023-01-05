//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_NAMED_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_NAMED_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/parse/named_error_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::named_error<Ch>::named_error(string_type &&_name, error_base &&_error)
    : name_{std::move(_name)}, error_{std::move(_error)}
{
}

template <typename Ch>
typename fcppt::parse::named_error<Ch>::string_type const &
fcppt::parse::named_error<Ch>::name() const
{
  return this->name_;
}

template <typename Ch>
typename fcppt::parse::named_error<Ch>::error_base const &
fcppt::parse::named_error<Ch>::error() const
{
  return this->error_;
}

template <typename Ch>
bool fcppt::parse::named_error<Ch>::operator==(named_error const &) const = default;

#endif
