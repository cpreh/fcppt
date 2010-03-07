//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_ROUND_DIV_INT_HPP_INCLUDED
#define FCPPT_MATH_ROUND_DIV_INT_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_unsigned.hpp>

namespace fcppt
{
namespace math
{

/// Rounds the division @a l / @a r
/**
 * @param T must be unsigned
*/
template<
	typename T
>
typename boost::enable_if<
	boost::is_unsigned<T>,
	T
>::type
round_div_int(
	T const l,
	T const r
)
{
	return (r % 2u)
		? ((l * 2u / r) + 1u) / 2u // for odd numbers up to half the types capacity
		: (l + (r / 2u)) / r;      // for even numbers at least up to half till up
		                           // to 100% of the types capacity, depending on r
		                           // greater r -> less max l
}
}
}

#endif
