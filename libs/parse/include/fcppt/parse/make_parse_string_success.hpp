//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_MAKE_PARSE_STRING_SUCCESS_HPP_INCLUDED
#define FCPPT_PARSE_MAKE_PARSE_STRING_SUCCESS_HPP_INCLUDED

#include <fcppt/either/make_success.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/parse/parse_string_error_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Creates a success value with a parse_string failure type.
\ingroup fcpptparse

The character type \a Ch of the error value has to be specified explicitly.
*/
template <typename Ch, typename Success>
inline fcppt::either::object<fcppt::parse::parse_string_error<Ch>, std::remove_cvref_t<Success>>
make_parse_string_success(Success &&_success)
{
  return fcppt::either::make_success<fcppt::parse::parse_string_error<Ch>>(
      std::forward<Success>(_success));
}
}

#endif
