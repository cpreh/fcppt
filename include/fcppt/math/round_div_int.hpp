//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_ROUND_DIV_INT_HPP_INCLUDED
#define FCPPT_MATH_ROUND_DIV_INT_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_integral.hpp>

namespace fcppt
{
namespace math
{
template<typename T>
typename boost::enable_if<boost::is_integral<T>, T>::type round_div_int(const T  l, const T r)
{
	return (r % 2)
		? ((l * 2 / r) + 1) / 2 // for odd numbers up to half the types capacity
		: (l + (r / 2)) / r;    // for even numbers at least up to half till up
		                        // to 100% of the types capacity, depending on r
		                        // greater r -> less max l
}
}
}

#endif
