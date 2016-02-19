//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_ENUM_RANGE_HPP_INCLUDED
#define FCPPT_MAKE_ENUM_RANGE_HPP_INCLUDED

#include <fcppt/enum_min_value.hpp>
#include <fcppt/enum_range_impl.hpp>
#include <fcppt/make_enum_range_start.hpp>


namespace fcppt
{

/**
\brief Creates an enum range over the whole enum

\ingroup fcpptenum

Creates the enum range [static_cast<Enum>(0), enum_max_value<Enum>::value].
*/
template<
	typename Enum
>
inline
fcppt::enum_range<
	Enum
>
make_enum_range()
{
	return
		fcppt::make_enum_range_start(
			fcppt::enum_min_value<
				Enum
			>::value
		);
}

}

#endif
