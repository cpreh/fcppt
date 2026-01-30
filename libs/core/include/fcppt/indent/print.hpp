//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_INDENT_PRINT_HPP_INCLUDED
#define FCPPT_INDENT_PRINT_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/indent/level.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::indent
{
/**
\brief Provides an output operator for indents.

\ingroup fcpptindent
*/
class print
{
public:
  explicit print(fcppt::indent::level const _level) : level_{_level} {}

  [[nodiscard]] fcppt::indent::level level() const { return this->level_; }

private:
  fcppt::indent::level level_;
};

template <typename Ch, typename Traits>
std::basic_ostream<Ch, Traits> &
operator<<(std::basic_ostream<Ch, Traits> &_stream, fcppt::indent::print const _print)
{
  return _stream << std::basic_string<Ch>(_print.level().get(), FCPPT_CHAR_LITERAL(Ch, ' '));
}
}

#endif
