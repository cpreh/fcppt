//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROTATION_AXIS_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROTATION_AXIS_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/object_impl.hpp>
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
/**
\brief Calculates a 4x4 rotation matrix around an arbitrary axis given as a unit vector
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\param angle The angle to rotate about
\param a The axis to rotate around

The resulting matrix will be static.

\see
fcppt::math::matrix::rotation_x

\see
fcppt::math::matrix::rotation_y

\see
fcppt::math::matrix::rotation_z

\see
fcppt::math::matrix::rotation_axis
*/
template
<
	typename T
>
static_<T, 4, 4> const
rotation_axis(
	T const angle,
	vector::static_<T,3> const &a
)
{
	T const
		sinx = std::sin(angle),
		cosx = std::cos(angle),
		cosxc = fcppt::literal<T>(1) - cosx,
		x = a.x(),
		y = a.y(),
		z = a.z(),
		zero = fcppt::literal<T>(0),
		one = fcppt::literal<T>(1);

	return
		static_<T, 4, 4>(
			cosx + x*x*cosxc,   x*y*cosxc - z*sinx, x*z*cosxc + y*sinx, zero,
			x*y*cosxc + z*sinx, cosx + y*y*cosxc,   y*z*cosxc - x*sinx, zero,
			x*z*cosxc - y*sinx, y*z*cosxc + x*sinx, cosx + z*z*cosxc,   zero,
			zero,               zero,               zero,               one);

}
}
}
}

#endif
