//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_OUTPUT_HPP_INCLUDED
#define FCPPT_OPTIONAL_OUTPUT_HPP_INCLUDED

#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Outputs an optional to a basic_ostream.

\ingroup fcpptoptional

TODO(concepts)
*/
template <typename Type, typename Ch, typename Traits>
std::basic_ostream<Ch, Traits> &
operator<<(std::basic_ostream<Ch, Traits> &_stream, fcppt::optional::object<Type> const &_opt_value)
{
  using result_type = std::basic_ostream<Ch, Traits> &;

  return fcppt::optional::maybe(
      _opt_value,
      [&_stream]() -> result_type { return _stream << _stream.widen('N'); },
      [&_stream](Type const &_value) -> result_type {
        return _stream << _stream.widen('J') << _stream.widen(' ') << _value;
      });
}

}

#endif
