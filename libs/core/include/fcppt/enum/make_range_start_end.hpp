//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_MAKE_RANGE_START_END_HPP_INCLUDED
#define FCPPT_ENUM_MAKE_RANGE_START_END_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/enum/range_impl.hpp>


namespace fcppt
{
namespace enum_
{

/**
\brief Creates a closed enum range

\ingroup fcpptenum

Creates the enum range [\a _start,\a _end]. The range must be closed
because there is no "one past the end" enum value.

\param _start The first element of the range.

\param _end The last element of the range.
*/
template<
	typename Enum
>
inline
fcppt::enum_::range<
	Enum
>
make_range_start_end(
	Enum const _start,
	Enum const _end
)
noexcept
{
	using
	result_type
	=
	fcppt::enum_::range<
		Enum
	>;

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
}

#endif
