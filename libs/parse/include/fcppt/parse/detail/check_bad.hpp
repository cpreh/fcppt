//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_CHECK_BAD_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_CHECK_BAD_HPP_INCLUDED

#include <fcppt/string_literal.hpp>
#include <fcppt/parse/detail/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
namespace detail
{
template <typename Ch>
inline void check_bad(std::basic_istream<Ch> &_stream)
{
  if (_stream.bad())
  {
    throw
        // NOLINTNEXTLINE(hicpp-exception-baseclass)
        fcppt::parse::detail::exception<Ch>{FCPPT_STRING_LITERAL(Ch, "stream failed.")};
  }
}

}
}
}

#endif
