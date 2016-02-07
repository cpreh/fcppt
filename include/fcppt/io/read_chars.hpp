//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_READ_CHARS_HPP_INCLUDED
#define FCPPT_IO_READ_CHARS_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/io/optional_buffer.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

/**
\brief Reads a number of chars

Tries to read \a count chars from \a stream.

\ingroup fcpptio
*/
FCPPT_DETAIL_SYMBOL
fcppt::io::optional_buffer
read_chars(
	std::istream &stream,
	std::size_t count
);

}
}

#endif
