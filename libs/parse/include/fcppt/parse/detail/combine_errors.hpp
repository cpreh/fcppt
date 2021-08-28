//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_COMBINE_ERRORS_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_COMBINE_ERRORS_HPP_INCLUDED

#include <fcppt/string_literal.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::detail
{
template <typename Ch>
[[nodiscard]] fcppt::parse::error<Ch>
combine_errors(fcppt::parse::error<Ch> &&_left_error, fcppt::parse::error<Ch> &&_right_error)
{
  return _right_error.is_fatal()
             ? std::move(_right_error)
             : fcppt::parse::error<Ch>(std::basic_string<Ch>(FCPPT_STRING_LITERAL(Ch, "{ "))) +
                   std::move(_left_error) +
                   fcppt::parse::error<Ch>(
                       std::basic_string<Ch>(FCPPT_STRING_LITERAL(Ch, " OR "))) +
                   std::move(_right_error) +
                   fcppt::parse::error<Ch>(std::basic_string<Ch>(FCPPT_STRING_LITERAL(Ch, " }")));
}
}
#endif
