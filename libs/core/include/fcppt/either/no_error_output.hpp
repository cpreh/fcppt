//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_NO_ERROR_OUTPUT_HPP_INCLUDED
#define FCPPT_EITHER_NO_ERROR_OUTPUT_HPP_INCLUDED

#include <fcppt/string_literal.hpp>
#include <fcppt/either/no_error_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Outputs #fcppt::either::no_error.

\ingroup fcppteither
*/
template <typename Ch, typename Traits>
inline std::basic_ostream<Ch, Traits> &
operator<<(std::basic_ostream<Ch, Traits> &_stream, fcppt::either::no_error const &)
{
  return _stream << FCPPT_STRING_LITERAL(Ch, "No error");
}

}

#endif
