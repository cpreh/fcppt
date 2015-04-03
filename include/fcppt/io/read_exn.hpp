//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_READ_EXN_HPP_INCLUDED
#define FCPPT_IO_READ_EXN_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/optional_to_exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/endianness/format_fwd.hpp>
#include <fcppt/io/read.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

/**
\brief Reads an object of fundamental type from a stream

\ingroup fcpptio

Reads a fundamental type \a Type from \a _stream using the endianness of \a
_format. The read will be done binary. If it fails, an exception will be
thrown.

\tparam Type Must be a fundamental type

\param _stream The stream to read from

\param _format The endianness to use

\return If the read is successful, the object will be returned.

\throw If the read is not successful, an fcppt::exception will be thrown
*/
template<
	typename Type
>
Type
read_exn(
	std::istream &_stream,
	fcppt::endianness::format const _format
)
{
	static_assert(
		std::is_fundamental<
			Type
		>::value,
		"io::read_exn must return a fundamental type"
	);

	return
		fcppt::optional_to_exception(
			fcppt::io::read<
				Type
			>(
				_stream,
				_format
			),
			[]
			{
				return
					fcppt::exception(
						FCPPT_TEXT("read_exn failed!")
					);
			}
		);
}

}
}

#endif
