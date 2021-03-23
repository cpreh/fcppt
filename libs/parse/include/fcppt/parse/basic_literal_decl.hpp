//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_LITERAL_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_LITERAL_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/basic_literal_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/is_char.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/tag.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Parses a specific character and returns nothing.

\ingroup fcpptparse

For a character c, the parser <code>basic_literal{c}</code> succeeds if the next input character is c.
Otherwise, an error is returned.
This parser returns #fcppt::unit on success.
*/
template <typename Ch>
class basic_literal : private fcppt::parse::tag
{
public:
  static_assert(fcppt::parse::is_char<Ch>::value);

  explicit basic_literal(Ch);

  using result_type = fcppt::unit;

  template <typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;
private:
  Ch ch_;
};

}
}

#endif
