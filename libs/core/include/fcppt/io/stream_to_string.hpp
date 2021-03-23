//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_STREAM_TO_STRING_HPP_INCLUDED
#define FCPPT_IO_STREAM_TO_STRING_HPP_INCLUDED

#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <sstream>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace io
{
/**
\brief Reads the contents of a stream into a string.

\ingroup fcpptstring
*/
template <typename Ch, typename Traits>
fcppt::optional::object<std::basic_string<Ch, Traits>>
stream_to_string(std::basic_istream<Ch, Traits> &_input)
{
  std::basic_ostringstream<Ch, Traits> output{}; // NOLINT(fuchsia-default-arguments-calls)

  output << _input.rdbuf();

  return fcppt::optional::make_if(
      // TODO(philipp): What should we check here?
      //_input.eof()
      !_input.fail() && (output.str().empty() || output.good()),
      [&output] { return std::move(output.str()); });
}

}
}

#endif
