//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_ENUM_RANGE_START_HPP_INCLUDED
#define FCPPT_MAKE_ENUM_RANGE_START_HPP_INCLUDED

#include <fcppt/enum_max_value.hpp>
#include <fcppt/enum_range_impl.hpp>
#include <fcppt/make_enum_range_start_end.hpp>


namespace fcppt
{

/**
\brief Creates an enum range with a custom start value

\ingroup fcpptenum

Creates the closed range [_start, enum_max_value<Enum>::value].

\param _start The first element of the range.
*/
template<
	typename Enum
>
inline
fcppt::enum_range<
	Enum
>
make_enum_range_start(
	Enum const _start
)
{
	return
		fcppt::make_enum_range_start_end(
			_start,
			fcppt::enum_max_value<
				Enum
			>::value
		);
}

}

#endif
