//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_WRITE_HPP_INCLUDED
#define FCPPT_IO_WRITE_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_char_ptr.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/endianness/convert.hpp>
#include <fcppt/config/external_begin.hpp>
#include <bit>
#include <ios>
#include <ostream>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::io
{
/**
\brief Writes an object of arithmetic type to a stream

\ingroup fcpptio

Writes \a _value to \a _stream using the endianness of \a _format. The write
will be done binary.

\tparam Type Must be an arithmetic type

\param _stream The stream to write to

\param _value The value to write

\param _format The endianness to use
*/
template <typename Type>
void write(std::ostream &_stream, Type const &_value, std::endian const _format)
{
  static_assert(std::is_arithmetic_v<Type>, "io::write can only be used on arithmetic types");

  Type const tmp(fcppt::endianness::convert(_value, _format));

  _stream.write(
      fcppt::cast::to_char_ptr<char const *>(&tmp),
      fcppt::cast::size<std::streamsize>(fcppt::cast::to_signed(sizeof(Type))));
}

}

#endif
