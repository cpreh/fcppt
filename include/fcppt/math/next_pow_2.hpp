//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_NEXT_POW_2_HPP_INCLUDED
#define FCPPT_MATH_NEXT_POW_2_HPP_INCLUDED

#include <fcppt/math/detail/next_pow_2.hpp>

namespace fcppt
{
namespace math
{

/// Calculates the next power of 2 for @a t
/**
 * @param T must either be an unsigned type or a floating point type
 * For unsigned types it will use multiplication.
 * For signed types it will use multiplication as well plus some additional checks.
 * For floating point types std::pow, std::ceil and std::log will be used.
*/
template<
	typename T
>
T
next_pow_2(
	T const t
)
{
	return
		detail::next_pow_2(
			t
		);
}

}
}

#endif
