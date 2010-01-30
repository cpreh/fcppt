//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_NEXT_POW_2_HPP_INCLUDED
#define FCPPT_MATH_NEXT_POW_2_HPP_INCLUDED

#include <fcppt/math/is_power_of_2.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <cmath>

namespace fcppt
{
namespace math
{

template<
	typename T
>
typename boost::enable_if<
	boost::is_unsigned<
		T
	>,
	T
>::type
next_pow_2(
	T const t)
{
	T const two(
		static_cast<T>(2)
	);

	if(is_power_of_2(t))
		return t * two;

	T counter(t);

	T ret(
		static_cast<T>(1)
	);

	while(counter /= two)
		ret *= two;

	return ret * two;
}

template<
	typename T
>
typename boost::disable_if<
	boost::is_unsigned<
		T
	>,
	T
>::type
next_pow_2(
	T const t)
{
	return static_cast<T>(
		std::pow(
			static_cast<T>(2),
			std::ceil(
				std::log(
					static_cast<double>(t)
				)
				/ std::log(
					static_cast<double>(2)
				)
			)
		)
	);
}

}
}

#endif
