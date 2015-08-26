//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_SCALING_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_SCALING_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/has_dim.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Calculates a 4x4 scaling matrix

\ingroup fcpptmathmatrix

\tparam T The matrix's <code>value_type</code>

\param _x Scaling in x direction

\param _y Scaling in y direction

\param _z Scaling in z direction

The resulting matrix will be static.
*/
template<
	typename T
>
fcppt::math::matrix::static_<
	T,
	4,
	4
>
scaling(
	T const _x,
	T const _y,
	T const _z
)
{
	T const
		zero{
			fcppt::literal<
				T
			>(
				0
			)
		},
		one{
			fcppt::literal<
				T
			>(
				1
			)
		};

	return
		fcppt::math::matrix::static_<
			T,
			4,
			4
		>(
			fcppt::math::matrix::row(
				   _x, zero, zero, zero
			),
			fcppt::math::matrix::row(
				zero,     _y,zero, zero
			),
			fcppt::math::matrix::row(
				zero,  zero,   _z, zero
			),
			fcppt::math::matrix::row(
				zero,  zero, zero,  one
			)
		);

}

/// Calculates a scaling matrix from a three dimensional vector
template<
	typename Vector
>
inline
fcppt::math::matrix::static_<
	typename
	Vector::value_type,
	4,
	4
>
scaling(
	// TODO: Use vector::static_
	Vector const &_vec
)
{
	static_assert(
		fcppt::math::vector::has_dim<
			Vector,
			3
		>::value,
		"matrix::scaling can only be used on three-dimensional vectors"
	);

	return
		fcppt::math::matrix::scaling(
			_vec.x(),
			_vec.y(),
			_vec.z()
		);
}

}
}
}

#endif
