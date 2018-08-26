//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_ENUM_RANGE_HPP_INCLUDED
#define FCPPT_BRIGAND_ENUM_RANGE_HPP_INCLUDED

#include <fcppt/brigand/enum_range_start_end.hpp>
#include <fcppt/enum/max_value.hpp>
#include <fcppt/enum/min_value.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief A brigand range over enums

\ingroup fcpptenum
*/
template<
	typename Enum
>
using
enum_range
=
fcppt::brigand::enum_range_start_end<
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
