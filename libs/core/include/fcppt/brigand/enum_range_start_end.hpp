//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_ENUM_RANGE_START_END_HPP_INCLUDED
#define FCPPT_BRIGAND_ENUM_RANGE_START_END_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/cast/int_to_enum_fun.hpp>
#include <fcppt/brigand/integral_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/range.hpp>
#include <brigand/types/args.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief An BRIGAND range over enums from a minimum to a maximum

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
::brigand::transform<
	::brigand::range<
		typename
		std::underlying_type<
			Enum
		>::type,
		fcppt::cast::enum_to_int<
			typename
			std::underlying_type<
				Enum
			>::type
		>(
			Start
		),
		fcppt::cast::enum_to_int<
			typename
			std::underlying_type<
				Enum
			>::type
		>(
			Max
		)
		+
		fcppt::literal<
			typename
			std::underlying_type<
				Enum
			>::type
		>(
			1
		)
	>,
	::brigand::bind<
		fcppt::brigand::integral_cast,
		Enum,
		fcppt::cast::int_to_enum_fun,
		::brigand::_1
	>
>;

}
}

#endif
