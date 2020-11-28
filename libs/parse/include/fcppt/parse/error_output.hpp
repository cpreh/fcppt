//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_ERROR_OUTPUT_HPP_INCLUDED
#define FCPPT_PARSE_ERROR_OUTPUT_HPP_INCLUDED

#include <fcppt/parse/error_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
template <typename Ch>
std::basic_ostream<Ch> &
operator<<(std::basic_ostream<Ch> &_stream, fcppt::parse::error<Ch> const &_error)
{
  return _stream << _error.get();
}

}
}

#endif
