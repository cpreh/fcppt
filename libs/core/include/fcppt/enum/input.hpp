//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_INPUT_HPP_INCLUDED
#define FCPPT_ENUM_INPUT_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/enum/from_string.hpp>
#include <fcppt/io/extract.hpp>
#include <fcppt/io/istream.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace enum_
{

/**
\brief Reads an enum value from a stream.

\ingroup fcpptenum

Uses \link fcppt::enum_::from_string\endlink to read an enum from \a _stream
and store it in \a _result. In case this fails, the failbit of \a _stream is set.
This function is useful to implement <code>operator>></code> for an enum type.

\tparam Enum Must be an enum type

\return \a _stream
*/
template<
	typename Enum
>
fcppt::io::istream &
input(
	fcppt::io::istream &_stream,
	Enum &_result
)
{
	static_assert(
		std::is_enum_v<
			Enum
		>,
		"Enum must be an enum type"
	);

	fcppt::optional::maybe_void(
		fcppt::io::extract<
			fcppt::string
		>(
			_stream
		),
		[
			&_result,
			&_stream
		](
			fcppt::string const &_value
		)
		{
			fcppt::optional::maybe(
				fcppt::enum_::from_string<
					Enum
				>(
					_value
				),
				[
					&_stream
				]{
					_stream.setstate(
						std::ios_base::failbit
					);
				},
				[
					&_result
				](
					Enum const _arg
				)
				{
					_result =
						_arg;
				}
			);
		}
	);

	return
		_stream;
}

}
}

#endif
