//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_POWER_OF_2_HPP_INCLUDED
#define FCPPT_MATH_POWER_OF_2_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Calculates two to the power of n

\ingroup fcpptmath

Returns <code>2 ^ _exponent</code>.

\tparam Exponent Must be an unsigned type.

\tparam Result Must be a type constructible with \ref fcppt.literal.
*/
template<
	typename Result,
	typename Exponent
>
inline
constexpr
Result
power_of_2(
	Exponent const _exponent
)
{
	static_assert(
		std::is_unsigned<
			Exponent
		>::value,
		"Exponent must be unsigned"
	);

	return
		fcppt::literal<
			Result
		>(
			1
		)
		<<
		_exponent;
}

}
}

#endif
