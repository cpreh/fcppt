//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROTATION_AXIS_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROTATION_AXIS_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
/// Calculates a rotation matrix around an arbitrary axis given as a unit vector
template
<
	typename T
>
typename static_<T, 4, 4>::type const
rotation_axis(
	T const angle,
	typename vector::static_<T,3>::type const &a
)
{
	T const
		sinx = std::sin(angle),
		cosx = std::cos(angle),
		cosxc = static_cast<T>(1) - cosx,
		x = a.x(),
		y = a.y(),
		z = a.z(),
		zero = static_cast<T>(0),
		one = static_cast<T>(1);

	return
		typename static_<T, 4, 4>::type(
			cosx + x*x*cosxc,   x*y*cosxc - z*sinx, x*z*cosxc + y*sinx, zero,
			x*y*cosxc + z*sinx, cosx + y*y*cosxc,   y*z*cosxc - x*sinx, zero,
			x*z*cosxc - y*sinx, y*z*cosxc + x*sinx, cosx + z*z*cosxc,   zero,
			zero,               zero,               zero,               one);

}
}
}
}

#endif
