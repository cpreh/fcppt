//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_WRITE_HPP_INCLUDED
#define FCPPT_IO_WRITE_HPP_INCLUDED

#include <fcppt/endianness/convert.hpp>
#include <fcppt/endianness/format_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <iosfwd>
#include <ostream>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

/**
\brief Writes an object of fundamental type to a stream

\ingroup fcpptio

Writes \a _value to \a _stream using the endianness of \a _format. The write
will be done binary.

\tparam Type Must be a fundamental type

\param _stream The stream to write to

\param _value The value to write

\param _format The endianness to use
*/
template<
	typename Type
>
typename boost::enable_if<
	std::is_fundamental<
		Type
	>,
	void
>::type
write(
	std::ostream &_stream,
	Type const &_value,
	fcppt::endianness::format const _format
)
{
	Type const tmp(
		fcppt::endianness::convert(
			_value,
			_format
		)
	);

	_stream.write(
		reinterpret_cast<
			char const *
		>(
			&tmp
		),
		static_cast<
			std::streamsize
		>(
			sizeof(
				Type
			)
		)
	);
}

}
}

#endif
