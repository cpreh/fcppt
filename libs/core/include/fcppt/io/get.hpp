//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_GET_HPP_INCLUDED
#define FCPPT_IO_GET_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace io
{
/**
\brief Gets a character from a stream

\ingroup fcpptio

Reads a character from \a _stream. Returns an empty optional for end-of-file.
*/
template <typename Ch, typename Traits>
fcppt::optional::object<Ch> get(std::basic_istream<Ch, Traits> &_stream)
{
  typename Traits::int_type const result{_stream.get()};

  using result_type = fcppt::optional::object<Ch>;

  return result == Traits::eof() ? result_type{} : result_type{Traits::to_char_type(result)};
}

}
}

#endif
