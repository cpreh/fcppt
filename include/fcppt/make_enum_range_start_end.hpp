//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_ENUM_RANGE_START_END_HPP_INCLUDED
#define FCPPT_MAKE_ENUM_RANGE_START_END_HPP_INCLUDED

#include <fcppt/enum_range_impl.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/cast/enum_to_int.hpp>


namespace fcppt
{

/**
\brief Creates a closed enum range

\ingroup fcpptenum

Creates the closed enum range [\a _start,\a _end]. The range must be closed
because there is no "one past the end" enum value.

\param _start The first element of the range.

\param _end The last element of the range.
*/
template<
	typename Enum
>
inline
fcppt::enum_range<
	Enum
>
make_enum_range_start_end(
	Enum const _start,
	Enum const _end
)
{
	typedef
	fcppt::enum_range<
		Enum
	>
	result_type;

	return
		result_type(
			fcppt::cast::enum_to_int<
				typename
				result_type::size_type
			>(
				_start
			),
			fcppt::cast::enum_to_int<
				typename
				result_type::size_type
			>(
				_end
			)
			+
			fcppt::literal<
				typename
				result_type::size_type
			>(
				1
			)
		);
}

}

#endif
