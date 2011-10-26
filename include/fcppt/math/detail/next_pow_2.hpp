//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_NEXT_POW_2_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_NEXT_POW_2_HPP_INCLUDED

#include <fcppt/math/is_power_of_2.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/type_traits/is_signed.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <boost/type_traits/make_unsigned.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
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
	T const t
)
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
typename boost::enable_if<
	boost::is_signed<
		T
	>,
	T
>::type
next_pow_2(
	T const t
)
{
	FCPPT_ASSERT(
		t >= 0
	);

	return
		static_cast<
			T
		>(
			next_pow_2(
				static_cast<
					typename boost::make_unsigned<
						T
					>::type
				>(
					t
				)
			)
		);
}

template<
	typename T
>
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	T
>::type
next_pow_2(
	T const t
)
{
	return
		std::pow(
			static_cast<T>(2),
			std::ceil(
				std::log(
					t
				)
				/ std::log(
					static_cast<T>(2)
				)
			)
		);
}

}
}
}

#endif
