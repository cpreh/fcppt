//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_WRITE_CHARS_HPP_INCLUDED
#define FCPPT_IO_WRITE_CHARS_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace io
{
/**
\brief Writes a number of chars

Tries to write \a count chars from \a data to \a stream.

\ingroup fcpptio

\return If the write operation succeeded.
*/
[[nodiscard]] FCPPT_DETAIL_SYMBOL bool
write_chars(std::ostream &stream, char const *data, std::size_t count);

}
}

#endif
