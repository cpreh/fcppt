//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_ENUM_RANGE_HPP_INCLUDED
#define FCPPT_MPL_ENUM_RANGE_HPP_INCLUDED

#include <fcppt/enum_max_value.hpp>
#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/mpl/enum_range_start_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief An MPL range over enums

\ingroup fcpptenum
*/
template<
	typename Enum
>
using enum_range
=
fcppt::mpl::enum_range_start_end<
	Enum,
	fcppt::cast::int_to_enum<
		Enum
	>(
		0
	),
	fcppt::enum_max_value<
		Enum
	>::value
>;

}
}

#endif
