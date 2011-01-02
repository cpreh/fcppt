//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_INVERSE_HPP_INCLUDED
#define FCPPT_MATH_INVERSE_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_integral.hpp>

namespace fcppt
{
namespace math
{

/// Calculates the inverse to a multiplication
/**
 * @tparam T must not be integral
 * Equal to 1 / @a t
*/
template<
	typename T
>
typename
boost::disable_if
<
	boost::is_integral<T>,
	T
>::type
inverse(
	T const t
)
{
	return
		static_cast<T>(1) / t;
}

}
}

#endif
