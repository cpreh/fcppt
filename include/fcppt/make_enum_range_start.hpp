//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_ENUM_RANGE_START_HPP_INCLUDED
#define FCPPT_MAKE_ENUM_RANGE_START_HPP_INCLUDED

#include <fcppt/enum_range_impl.hpp>
#include <fcppt/enum_size.hpp>
#include <fcppt/cast/enum_to_int.hpp>


namespace fcppt
{

template<
	typename Enum
>
fcppt::enum_range<
	Enum
>
make_enum_range_start(
	Enum const _start
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
			fcppt::enum_size<
				Enum
			>::value
		);
}

}

#endif
