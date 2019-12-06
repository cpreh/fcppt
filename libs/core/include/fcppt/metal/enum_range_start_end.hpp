//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_ENUM_RANGE_START_END_HPP_INCLUDED
#define FCPPT_METAL_ENUM_RANGE_START_END_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/cast/int_to_enum_fun.hpp>
#include <fcppt/metal/interval.hpp>
#include <fcppt/type_traits/integral_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief A metal range over enums from a minimum to a maximum.

\ingroup fcpptenum
*/
template<
	typename Enum,
	Enum Start,
	Enum Max
>
using
enum_range_start_end
=
::metal::transform<
	::metal::bind<
		::metal::lambda<
			fcppt::type_traits::integral_cast
		>,
		::metal::always<
			Enum
		>,
		::metal::always<
			fcppt::cast::int_to_enum_fun
		>,
		::metal::_1
	>,
	fcppt::metal::interval<
		std::underlying_type_t<
			Enum
		>,
		fcppt::cast::enum_to_int<
			std::underlying_type_t<
				Enum
			>
		>(
			Start
		),
		fcppt::cast::enum_to_int<
			std::underlying_type_t<
				Enum
			>
		>(
			Max
		)
		+
		fcppt::literal<
			std::underlying_type_t<
				Enum
			>
		>(
			1
		)
	>
>;

}
}

#endif
