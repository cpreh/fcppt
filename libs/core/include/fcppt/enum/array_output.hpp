//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_ARRAY_OUTPUT_HPP_INCLUDED
#define FCPPT_ENUM_ARRAY_OUTPUT_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/enum/array_impl.hpp>
#include <fcppt/enum/make_range.hpp>
#include <fcppt/enum/to_string.hpp>
#include <fcppt/io/ostream.hpp>


namespace fcppt
{
namespace enum_
{

/**
\brief Outputs an enum array.

\ingroup fcpptenum
*/
template<
	typename Enum,
	typename Value
>
fcppt::io::ostream &
operator<<(
	fcppt::io::ostream &_stream,
	fcppt::enum_::array<
		Enum,
		Value
	> const &_array
)
{
	_stream
		<<
		FCPPT_TEXT('[');

	for(
		Enum const value
		:
		fcppt::enum_::make_range<
			Enum
		>()
	)
		_stream
			<<
			fcppt::enum_::to_string(
				value
			)
			<<
			FCPPT_TEXT(" = ")
			<<
			_array[
				value
			]
			<<
			FCPPT_TEXT(", ");

	_stream
		<<
		FCPPT_TEXT(']');

	return
		_stream;
}

}
}

#endif
