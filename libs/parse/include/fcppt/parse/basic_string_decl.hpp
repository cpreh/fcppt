//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_STRING_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_STRING_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/basic_string_fwd.hpp>
#include <fcppt/parse/is_char.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Parses a specific string and returns nothing.

\ingroup fcpptparse

For a string <code>c_1...c_n</code>, the parser <code>basic_string{c_1...c_n}</code> succeeds if the next inputs characters are c_1, ..., c_n.
Otherwise, an error is returned.
This parser returns #fcppt::unit on success.
*/
template <typename Ch>
class basic_string : private fcppt::parse::tag
{
public:
  static_assert(fcppt::parse::is_char<Ch>::value);

  explicit basic_string(std::basic_string<Ch> &&);

  using result_type = fcppt::unit;

  template <typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;
private:
  std::basic_string<Ch> string_;
};

}

#endif
