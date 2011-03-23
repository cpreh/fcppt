//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIFF_HPP_INCLUDED
#define FCPPT_MATH_DIFF_HPP_INCLUDED

#include <fcppt/math/detail/diff.hpp>

namespace fcppt
{
namespace math
{

/// Calculates the absolute distance between @a a and @a b
/**
 * For unsigned types it returns min(@a a - @a b, @a b - @a a).
 * Otherwise abs(@a a - @a b) is returned.
*/
template<
	typename T
>
T
diff(
	T const &_a,
	T const &_b
)
{
	return
		detail::diff(
			_a,
			_b
		);
}

}
}

#endif
