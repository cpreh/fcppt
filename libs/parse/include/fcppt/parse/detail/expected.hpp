//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_EXPECTED_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_EXPECTED_HPP_INCLUDED

#include <fcppt/output_to_string.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/location.hpp>
#include <fcppt/parse/location_output.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
namespace detail
{
template <typename Ch>
fcppt::parse::error<Ch>
expected(fcppt::parse::position<Ch> const _pos, std::basic_string<Ch> &&_expected, Ch const _got)
{
  return fcppt::parse::error<Ch>{
      fcppt::optional::maybe(
          _pos.location(),
          [] { return std::basic_string<Ch>{}; },
          [](fcppt::parse::location const &_location) {
            return std::basic_string<Ch>{FCPPT_STRING_LITERAL(Ch, "Line ")} +
                   fcppt::output_to_string<std::basic_string<Ch>>(_location) +
                   std::basic_string<Ch>{FCPPT_STRING_LITERAL(Ch, ": ")};
          }) +
      FCPPT_STRING_LITERAL(Ch, "Expected ") + std::move(_expected) +
      FCPPT_STRING_LITERAL(Ch, ", got ") + _got};
}

}
}
}

#endif
