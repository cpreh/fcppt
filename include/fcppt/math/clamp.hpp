//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_CLAMP_HPP_INCLUDED
#define FCPPT_MATH_CLAMP_HPP_INCLUDED

#include <fcppt/assert.hpp>
#include <algorithm>

namespace fcppt
{
namespace math
{

/// Clamps @a value into the range [@a min, @a max]
/**
 * Requires vmin <= vmax
*/
template<
	typename T
>
T
clamp(
	T const &value,
	T const &vmin,
	T const &vmax
)
{
	FCPPT_ASSERT(
		vmin <= vmax
	);

	return std::max(
		std::min(
			value,
			vmax
		),
		vmin
	);
}

}
}

#endif
