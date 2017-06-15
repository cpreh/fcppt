//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_MAKE_RANGE_HPP_INCLUDED
#define FCPPT_ENUM_MAKE_RANGE_HPP_INCLUDED

#include <fcppt/enum/make_range_start.hpp>
#include <fcppt/enum/min_value.hpp>
#include <fcppt/enum/range_impl.hpp>


namespace fcppt
{
namespace enum_
{

/**
\brief Creates an enum range over the whole enum

\ingroup fcpptenum

Creates the enum range <code>[fcppt::enum_::min_value<Enum>::value, fcppt::enum_::max_value<Enum>::value]</code>.
*/
template<
	typename Enum
>
inline
fcppt::enum_::range<
	Enum
>
make_range()
noexcept
{
	return
		fcppt::enum_::make_range_start(
			fcppt::enum_::min_value<
				Enum
			>::value
		);
}

}
}

#endif
