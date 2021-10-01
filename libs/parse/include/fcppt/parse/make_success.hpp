//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_MAKE_SUCCESS_HPP_INCLUDED
#define FCPPT_PARSE_MAKE_SUCCESS_HPP_INCLUDED

#include <fcppt/either/make_success.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Creates an fcppt::parse::result from a success value.
\ingroup fcpptparse

The character type \a Ch of the error value has to be specified explicitly.
*/
template <typename Ch, typename Success>
inline fcppt::parse::result<Ch, std::remove_cvref_t<Success>>
make_success(Success &&_success)
{
  return fcppt::either::make_success<fcppt::parse::error<Ch>>(std::forward<Success>(_success));
}
}

#endif
