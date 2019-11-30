//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_ENUM_RANGE_HPP_INCLUDED
#define FCPPT_METAL_ENUM_RANGE_HPP_INCLUDED

#include <fcppt/metal/enum_range_start_end.hpp>
#include <fcppt/enum/max_value.hpp>
#include <fcppt/enum/min_value.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief A metal range over enums.

\ingroup fcpptenum
*/
template<
	typename Enum
>
using
enum_range
=
fcppt::metal::enum_range_start_end<
	Enum,
	fcppt::enum_::min_value<
		Enum
	>::value,
	fcppt::enum_::max_value<
		Enum
	>::value
>;

}
}

#endif
