//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_MAKE_RANGE_START_HPP_INCLUDED
#define FCPPT_ENUM_MAKE_RANGE_START_HPP_INCLUDED

#include <fcppt/enum/make_range_start_end.hpp>
#include <fcppt/enum/max_value.hpp>
#include <fcppt/enum/range_impl.hpp>


namespace fcppt
{
namespace enum_
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
fcppt::enum_::range<
	Enum
>
make_range_start(
	Enum const _start
)
noexcept
{
	return
		fcppt::enum_::make_range_start_end(
			_start,
			fcppt::enum_::max_value<
				Enum
			>::value
		);
}

}
}

#endif
