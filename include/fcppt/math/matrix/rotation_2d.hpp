//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROTATION_2D_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROTATION_2D_HPP_INCLUDED

#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <cmath>

namespace fcppt
{
namespace math
{
namespace matrix
{

/// Calculates a two dimensional rotation matrix
/**
 * This matrix will rotate around an imaginary z axis
*/
template<
	typename T
>
typename static_<T, 2, 2>::type const
rotation_2d(
	T const angle
)
{
	T const
		sinx = std::sin(angle),
        	cosx = std::cos(angle);

	return
		typename static_<T, 2, 2>::type(
			cosx, -sinx,
			sinx,  cosx
		);
}

}
}
}

#endif
