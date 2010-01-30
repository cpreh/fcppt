//          Copyright Carl Philipp Reh 2009 - 2010.
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

template<
	typename T
>
inline bool
almost_zero(
	T const &t)
{
	return compare(
		t,
		static_cast<T>(0)
	);
}

}
}

#endif
