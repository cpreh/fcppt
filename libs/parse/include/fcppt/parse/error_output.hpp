//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_ERROR_OUTPUT_HPP_INCLUDED
#define FCPPT_PARSE_ERROR_OUTPUT_HPP_INCLUDED

#include <fcppt/indent/start.hpp>
#include <fcppt/parse/error_fwd.hpp>
#include <fcppt/parse/detail/print_error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
template <typename Ch>
std::basic_ostream<Ch> &
operator<<(std::basic_ostream<Ch> &_stream, fcppt::parse::error<Ch> const &_error)
{
  fcppt::parse::detail::print_error(_stream, _error, fcppt::indent::start());
  return _stream;
}

}

#endif
