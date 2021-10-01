//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_CHAR_SET_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_SET_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_char_set_container.hpp>
#include <fcppt/parse/basic_char_set_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Parses a set of characters and returns which one has matched.

\ingroup fcpptparse

For the character set <code>S</code>, this parser returns <code>c</code> if c is the next input character and c is in S.
Otherwise, an error is returned.

Note that instead of using <code>basic_char_set{c_1,...,c_n}</code>,
one could also use <code>P = basic_char{c_1} | ... | basic_char{c_n}</code>.
However, basic_char_set is more efficient, since it looks up the next character in a hash map,
whereas P would first try to match against c_1, then c_2, and so on.
*/
template <typename Ch>
class basic_char_set : private fcppt::parse::tag
{
public:
  using char_set_type = fcppt::parse::basic_char_set_container<Ch>;

  basic_char_set(std::initializer_list<Ch> const &);

  explicit basic_char_set(char_set_type &&);

  using result_type = Ch;

  template <typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

  [[nodiscard]] char_set_type const &chars() const;

private:
  char_set_type chars_;
};

}

#endif
