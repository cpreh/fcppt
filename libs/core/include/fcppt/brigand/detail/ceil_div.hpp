//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_DETAIL_CEIL_DIV_HPP_INCLUDED
#define FCPPT_BRIGAND_DETAIL_CEIL_DIV_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{
namespace detail
{

template<
	typename Type,
	Type Dividend,
	Type Divisor
>
struct ceil_div
:
std::integral_constant<
	Type,
	Dividend
	/
	Divisor
	+
	(
		Dividend
		%
		Divisor
		?
			1u
		:
			0u
	)
>
{
	static_assert(
		Divisor
		!=
		fcppt::literal<
			Type
		>(
			0
		),
		"Divisor cannot be zero"
	);

	static_assert(
		std::is_unsigned<
			Type
		>::value,
		"ceil_div only works on unsigned types"
	);
};

}
}
}

#endif
