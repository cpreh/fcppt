//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_NEGATIVE_HPP_INCLUDED
#define FCPPT_MATH_IS_NEGATIVE_HPP_INCLUDED

#include <fcppt/math/null.hpp>

namespace fcppt
{
namespace math
{

/// Checks if @a t is negative
/**
 * It uses fcppt::math::null<T>() to compare against zero.
*/
template<
	typename T
>
bool
is_negative(
	T const &t
)
{
	return 
		t < fcppt::math::null<T>();
}

}
}

#endif
