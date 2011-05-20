//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_SIGNUM_HPP_INCLUDED
#define FCPPT_MATH_SIGNUM_HPP_INCLUDED

#include <fcppt/math/detail/signum.hpp>

namespace fcppt
{
namespace math
{

/// Returns the sign of @a t.
/**
 * @return -1 indicates a negative sign,
 *          0 indicates no sign,
 *          1 indicates a positive sign
*/
template<
	typename T
>
inline
T
signum(
	T const t
)
{
	return
		detail::signum(
			t
		);
}

}
}

#endif
