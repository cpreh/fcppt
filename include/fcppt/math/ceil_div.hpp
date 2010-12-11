//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_CEIL_DIV_HPP_INCLUDED
#define FCPPT_MATH_CEIL_DIV_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_unsigned.hpp>

namespace fcppt
{
namespace math
{

/// Calculates dividend / divisor rounded towards infinity
template<
	typename T
>
typename boost::enable_if<
	boost::is_unsigned<
		T
	>,
	T
>::type
ceil_div(
	T const &_dividend,
	T const &_divisor
)
{
	return
		_dividend
		/ _divisor
		+
		(
			_dividend
			% _divisor
			?
				1u
			:
				0u
		);
}

}
}

#endif
