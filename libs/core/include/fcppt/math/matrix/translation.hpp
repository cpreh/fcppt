//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_TRANSLATION_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_TRANSLATION_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Calculates a 4x4 translation matrix from three coordinates

\ingroup fcpptmathmatrix

\param _x The x translation

\param _y The y translation

\param _z The z translation
*/
template<
	typename T
>
fcppt::math::matrix::static_<
	T,
	4,
	4
>
translation(
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
				one, zero, zero, _x
			),
			fcppt::math::matrix::row(
				zero, one, zero, _y
			),
			fcppt::math::matrix::row(
				zero, zero, one, _z
			),
			fcppt::math::matrix::row(
				zero, zero, zero, one
			)
		);
}

/**
\brief Calculates a 4x4 translation matrix from a three-dimensional vector

\ingroup fcpptmathmatrix

\param _vec A three-dimensional vector
*/
template<
	typename T,
	typename S
>
inline
fcppt::math::matrix::static_<
	T,
	4,
	4
>
translation(
	fcppt::math::vector::object<
		T,
		3,
		S
	> const &_vec
)
{
	return
		fcppt::math::matrix::translation(
			_vec.x(),
			_vec.y(),
			_vec.z()
		);
}

}
}
}

#endif
