//          Copyright Carl Philipp Reh 2009 - 2012.
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

/**
\brief Calculates the absolute distance between \p a and \p b
\ingroup fcpptmath
\tparam T A numeric type

For unsigned types, this returns:

\f[
\min(a - b, b - a)
\f]

For other types, <code>abs(a-b)</code> is returned.
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
