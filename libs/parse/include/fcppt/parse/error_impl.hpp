//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/parse/error_decl.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::error<Ch>::error(variant_type &&_value, fcppt::parse::is_fatal const _is_fatal)
: value_{std::move(_value)}, is_fatal_{_is_fatal.get()}
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)

template <typename Ch>
bool fcppt::parse::error<Ch>::is_fatal() const
{
  return this->is_fatal_;
}

FCPPT_PP_POP_WARNING

template <typename Ch>
typename fcppt::parse::error<Ch>::variant_type &fcppt::parse::error<Ch>::get()
{
  return this->value_;
}

template <typename Ch>
typename fcppt::parse::error<Ch>::variant_type const &fcppt::parse::error<Ch>::get() const
{
  return this->value_;
}

#endif
