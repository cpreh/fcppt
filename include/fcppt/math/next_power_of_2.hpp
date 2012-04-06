//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_NEXT_POWER_OF_2_HPP_INCLUDED
#define FCPPT_MATH_NEXT_POWER_OF_2_HPP_INCLUDED

#include <fcppt/math/is_power_of_2.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Calculates the next power of 2 for an unsigned value
\ingroup fcpptmath
\tparam T An unsigned type
*/
template<
	typename T
>
typename boost::enable_if<
	boost::is_unsigned<
		T
	>,
	T
>::type
next_power_of_2(
	T const _value
)
{
	T const two(
		static_cast<T>(2)
	);

	if(
		fcppt::math::is_power_of_2(
			_value
		)
	)
		return _value * two;

	T counter(
		_value
	);

	T ret(
		static_cast<T>(1u)
	);

	while(
		counter /= two
	)
		ret *= two;

	return ret * two;
}

}
}

#endif
