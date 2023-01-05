//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_ALTERNATIVE_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_ALTERNATIVE_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/recursive_comparison.hpp>
#include <fcppt/parse/alternative_error_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::alternative_error<Ch>::alternative_error(
    error_base &&_left, error_base &&_right)
    : left_{std::move(_left)}, right_{std::move(_right)}
{
}

template <typename Ch>
typename fcppt::parse::alternative_error<Ch>::error_base const &
fcppt::parse::alternative_error<Ch>::left() const
{
  return this->left_;
}

template <typename Ch>
typename fcppt::parse::alternative_error<Ch>::error_base const &
fcppt::parse::alternative_error<Ch>::right() const
{
  return this->right_;
}

template <typename Ch>
bool fcppt::parse::alternative_error<Ch>::operator==(alternative_error const &) const = default;

#endif
