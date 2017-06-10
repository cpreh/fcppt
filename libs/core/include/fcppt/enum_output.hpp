//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_OUTPUT_HPP_INCLUDED
#define FCPPT_ENUM_OUTPUT_HPP_INCLUDED

#include <fcppt/enum_to_string.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Outputs an enum value to a stream.

\ingroup fcpptenum

Uses \link fcppt::enum_to_string\endlink to output \a _value to \a _stream.
This function is useful to implement <code>operator<<</code> for an enum type.

\tparam Enum Must be an enum type

\return \a _stream
*/
template<
	typename Enum
>
fcppt::io::ostream &
enum_output(
	fcppt::io::ostream &_stream,
	Enum const _value
)
{
	static_assert(
		std::is_enum<
			Enum
		>::value,
		"Enum must be an enum type"
	);

	return
		_stream
		<<
		fcppt::enum_to_string(
			_value
		);
}

}

#endif
