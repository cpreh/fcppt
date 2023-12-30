//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_BASIC_STRING_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_BASIC_STRING_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/is_char.hpp>
#include <fcppt/parse/skipper/basic_string_fwd.hpp> // IWYU pragma: keep
#include <fcppt/parse/skipper/result_fwd.hpp>
#include <fcppt/parse/skipper/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::skipper
{
template <typename Ch>
class basic_string : private fcppt::parse::skipper::tag
{
public:
  static_assert(fcppt::parse::is_char<Ch>::value);

  explicit basic_string(std::basic_string<Ch> &&);

  [[nodiscard]] fcppt::parse::skipper::result<Ch>
  skip(fcppt::reference<fcppt::parse::basic_stream<Ch>>) const;
private:
  std::basic_string<Ch> string_;
};
}

#endif
