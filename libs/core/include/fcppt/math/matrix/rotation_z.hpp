//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROTATION_Z_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROTATION_Z_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/matrix/row.hpp>
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

\param _angle The angle to rotate about

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
fcppt::math::matrix::static_<
	T,
	4,
	4
>
rotation_z(
	T const _angle
)
{
	T const
		sinx{
			std::sin(
				_angle
			)
		},
		cosx{
			std::cos(
				_angle
			)
		},
		one{
			fcppt::literal<
				T
			>(
				1
			)
		},
		zero{
			fcppt::literal<
				T
			>(
				0
			)
		};

	return
		fcppt::math::matrix::static_<
			T,
			4,
			4
		>(
			fcppt::math::matrix::row(
				cosx, -sinx, zero, zero
			),
			fcppt::math::matrix::row(
				sinx,  cosx, zero, zero
			),
			fcppt::math::matrix::row(
				zero,  zero,  one, zero
			),
			fcppt::math::matrix::row(
				zero,  zero, zero,  one
			)
		);

}

}
}
}

#endif
