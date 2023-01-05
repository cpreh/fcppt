//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_COMBINE_ERRORS_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_COMBINE_ERRORS_HPP_INCLUDED

#include <fcppt/make_recursive.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/parse/alternative_error_impl.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::detail
{
template <typename Ch>
[[nodiscard]] fcppt::parse::error<Ch>
combine_errors(fcppt::parse::error<Ch> &&_left_error, fcppt::parse::error<Ch> &&_right_error)
{
  fcppt::parse::is_fatal const is_fatal{_left_error.is_fatal() || _right_error.is_fatal()};

  return fcppt::parse::error<Ch>{
      fcppt::parse::error_variant<Ch>{fcppt::parse::alternative_error<Ch>{
          fcppt::make_recursive(std::move(_left_error)),
          fcppt::make_recursive(std::move(_right_error))}},
      is_fatal};
}
}
#endif
