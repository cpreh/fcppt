//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_CEIL_DIV_SIGNED_HPP_INCLUDED
#define FCPPT_MATH_CEIL_DIV_SIGNED_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/math/ceil_div.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Calculates dividend / divisor rounded towards infinity
\tparam T A signed type
\ingroup fcpptmath
\param _dividend The dividend
\param _divisor The divisor
*/
template<
	typename T
>
T
ceil_div_signed(
	T const &_dividend,
	T const &_divisor
)
{
	static_assert(
		std::is_signed<
			T
		>::value,
		"ceil_div_signed can only be used on signed types"
	);

	return
		(
			_dividend
			<
			fcppt::literal<
				T
			>(
				0
			)
		)
		?
			_dividend
			/
			_divisor
		:
			fcppt::cast::to_signed(
				fcppt::math::ceil_div(
					fcppt::cast::to_unsigned(
						_dividend
					),
					fcppt::cast::to_unsigned(
						_divisor
					)
				)
			)
		;
}

}
}

#endif
