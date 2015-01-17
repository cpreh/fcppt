//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROTATION_Z_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROTATION_Z_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
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
\brief Calculates a 4x4 rotation matrix around the z axis
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\param angle The angle to rotate about

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
template<
	typename T
>
static_<T, 4, 4> const
rotation_z(
	T const angle
)
{
	T const
		sinx = std::sin(angle),
		cosx = std::cos(angle),
		one = fcppt::literal<T>(1),
		zero = fcppt::literal<T>(0);

	return
		static_<T, 4, 4>(
			cosx, -sinx, zero, zero,
			sinx,  cosx, zero, zero,
			zero,  zero,  one, zero,
			zero,  zero, zero,  one
		);

}

}
}
}

#endif
