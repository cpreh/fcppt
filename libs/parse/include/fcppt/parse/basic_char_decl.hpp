//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_CHAR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_char_fwd.hpp> // IWYU pragma: keep
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/is_char.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/tag.hpp>

namespace fcppt::parse
{
/**
\brief Parses a single character and returns it.

\ingroup fcpptparse

In case the next input character is <code>c</code>, then <code>c</code> is returned.
Otherwise, an error is returned.
*/
template <typename Ch>
class basic_char : private fcppt::parse::tag
{
public:
  static_assert(fcppt::parse::is_char<Ch>::value);

  basic_char();

  using result_type = Ch;

  template <typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;
};

}

#endif
