//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_COMPARE_HPP_INCLUDED
#define FCPPT_MATH_COMPARE_HPP_INCLUDED

#include <fcppt/math/detail/compare.hpp>

namespace fcppt
{
namespace math
{

/// Compares two values with a special case for floats
/**
 * For floats the function checks if they are almost the same
 * because floating point comparison with != or == is unsafe.
 * For all other types == will be used.
*/
template<
	typename T
>
inline
bool
compare(
	T const &a,
	T const &b
)
{
	return
		detail::compare(
			a,
			b
		);
}

}
}

#endif
