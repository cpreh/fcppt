//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_READ_HPP_INCLUDED
#define FCPPT_IO_READ_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_char_ptr.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/endianness/convert.hpp>
#include <fcppt/endianness/format.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <istream>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace io
{
/**
\brief Reads an object of arithmetic type from a stream

\ingroup fcpptio

Reads an arithmetic type \a Type from \a _stream using the endianness of \a
_format. The read will be done binary. If it fails, an empty optional will be
returned.

\tparam Type Must be an arithmetic type

\param _stream The stream to read from

\param _format The endianness to use

\return If the read is successful, an optional containing the read object will
be returned. Otherwise an empty optional will be returned.
*/
template <typename Type>
fcppt::optional::object<Type> read(std::istream &_stream, fcppt::endianness::format const _format)
{
  static_assert(std::is_arithmetic_v<Type>, "io::read must return an arithmetic type");

  using result_type = fcppt::optional::object<Type>;

  Type result;

  return _stream.read(
             fcppt::cast::to_char_ptr<char *>(&result),
             fcppt::cast::size<std::streamsize>(fcppt::cast::to_signed(sizeof(Type))))
             ? result_type(fcppt::endianness::convert(result, _format))
             : result_type();
}

}
}

#endif
