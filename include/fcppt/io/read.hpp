//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_READ_HPP_INCLUDED
#define FCPPT_IO_READ_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/endianness/convert.hpp>
#include <fcppt/endianness/format.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <iosfwd>
#include <istream>
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
_format. The read will be done binary. If it fails, an empty optional will be
returned.

\tparam Type Must be a fundamental type

\param _stream The stream to read from

\param _format The endianness to use

\return If the read is successful, an optional containing the read object will
be returned. Otherwise an empty optional will be returned.
*/
template<
	typename Type
>
typename boost::enable_if<
	std::is_fundamental<
		Type
	>,
	fcppt::optional<
		Type
	>
>::type
read(
	std::istream &_stream,
	fcppt::endianness::format const _format
)
{
	typedef fcppt::optional<
		Type
	> result_type;

	Type result;

	return
		_stream.read(
			reinterpret_cast<
				char *
			>(
				&result
			),
			static_cast<
				std::streamsize
			>(
				sizeof(
					Type
				)
			)
		)
		?
			result_type(
				fcppt::endianness::convert(
					result,
					_format
				)
			)
		:
			result_type()
		;
}

}
}

#endif
