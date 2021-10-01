//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_STREAM_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_STREAM_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/position_fwd.hpp>

namespace fcppt::parse
{
/**
\brief The stream class used while parsing.
\ingroup fcpptparse

This class is the base class for all input streams.
Semantically, a <code>basic_stream</code> points to an index 0 <= i <= n in a string <code>a_1...a_n</code> of type <code>vector<Ch></code>.
This index is \em before the next character that will be read,
or in case i = n the end of the string is reached.

The \em position of a stream is an index plus the current \em line number l and \em column number c.
These can be obtained as follows:
<ul>
<li>The current line number l is the number of newline characters plus one between c_1 and c_i (inclusive).</li>
<li>Let j <= i be the last newline character, or j=0 in case this does not exist. Then the current column number is c = i - j + 1.</li>
</ul>
An actual implementation would keep track of these numbers when <code>get_char</code> and <code>set_position</code> are called.
This is also the reason why <code>std::basic_istream</code> is not used, since implementing this with streambufs alone is impossible.
*/
template <typename Ch>
class basic_stream
{
  FCPPT_NONMOVABLE(basic_stream);

public:
  basic_stream();

  virtual ~basic_stream() = 0;

  /**
  \brief Returns the next character, if possible.
  If i = n, then the result is nothing.
  Otherwise, returns c_{i+1} and increments i.
  */
  [[nodiscard]] virtual fcppt::optional::object<Ch> get_char() = 0;

  /**
  \brief Returns the current position.
  */
  [[nodiscard]] virtual fcppt::parse::position<Ch> get_position() const = 0;

  /**
  \brief Sets the current position.

  Note that the position contains line and column numbers.
  These must be consistent with the string that is currently being read.
  Therefore, arguments to this function should only be values returned from get_position.
  */
  virtual void set_position(fcppt::parse::position<Ch> const &) = 0;
};

}

#endif
