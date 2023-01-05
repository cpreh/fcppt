//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TEST_PARSE_SKIPPER_MAKE_SUCCESS_HPP_INCLUDED
#define FCPPT_TEST_PARSE_SKIPPER_MAKE_SUCCESS_HPP_INCLUDED

#include <fcppt/either/make_success.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/parse/parse_string_error.hpp>
#include <fcppt/parse/skipper/result.hpp>

namespace fcppt::test::parse::skipper
{

template <typename Ch>
[[nodiscard]] inline fcppt::either::error<fcppt::parse::parse_string_error<Ch>> make_success()
{
  return fcppt::either::make_success<fcppt::parse::parse_string_error<Ch>>(
      fcppt::either::no_error{});
}
}

#endif
