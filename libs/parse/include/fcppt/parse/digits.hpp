//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DIGITS_HPP_INCLUDED
#define FCPPT_PARSE_DIGITS_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/parse/basic_char_set_impl.hpp>

namespace fcppt
{
namespace parse
{
template <typename Ch>
fcppt::parse::basic_char_set<Ch> digits()
{
  return fcppt::parse::basic_char_set<Ch>{
      FCPPT_CHAR_LITERAL(Ch, '0'),
      FCPPT_CHAR_LITERAL(Ch, '1'),
      FCPPT_CHAR_LITERAL(Ch, '2'),
      FCPPT_CHAR_LITERAL(Ch, '3'),
      FCPPT_CHAR_LITERAL(Ch, '4'),
      FCPPT_CHAR_LITERAL(Ch, '5'),
      FCPPT_CHAR_LITERAL(Ch, '6'),
      FCPPT_CHAR_LITERAL(Ch, '7'),
      FCPPT_CHAR_LITERAL(Ch, '8'),
      FCPPT_CHAR_LITERAL(Ch, '9')};
}

}
}

#endif
