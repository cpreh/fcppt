//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_ALMOST_ZERO_HPP_INCLUDED
#define FCPPT_MATH_ALMOST_ZERO_HPP_INCLUDED

#include <fcppt/math/compare.hpp>

namespace fcppt
{
namespace math
{

/// Compares the argument against 0
/**
 * For floats it will check if the value is almost zero.
 * All other types will be checked with ==.
*/
template<
	typename T
>
inline bool
almost_zero(
	T const &t
)
{
	return compare(
		t,
		static_cast<T>(0)
	);
}

}
}

#endif
