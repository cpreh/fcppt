//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_SQRT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_SQRT_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/identity.hpp>
#include <fcppt/math/matrix/infinity_norm.hpp>
#include <fcppt/math/matrix/inverse.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/*
\ingroup fcpptmathmatrix

Calculates the square root of a matrix. This function is intentionally not part
of the public fcppt API. It needs to be tested more, and maybe generalized so
that "epsilon" is more meaningful to users.
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
fcppt::math::matrix::static_<
	T,
	N,
	N
>
sqrt(
	fcppt::math::matrix::object<
		T,
		N,
		N,
		S
	> const &_matrix,
	T const _epsilon
)
{
	static_assert(
		std::is_floating_point<
			T
		>::value,
		"matrix::sqrt can only be used on floating point types"
	);

	typedef
	fcppt::math::matrix::static_<
		T,
		N,
		N
	>
	matrix_type;

	matrix_type
		X(
			_matrix
		),
		Y(
			fcppt::math::matrix::identity<
				matrix_type
			>()
		);

	while(fcppt::math::matrix::infinity_norm(X * X - _matrix) > _epsilon)
	{
		matrix_type const inverse_X =
			fcppt::math::matrix::inverse(
				X);

		X =
			fcppt::literal<T>(
				0.5) *
			(X + fcppt::math::matrix::inverse(Y));

		Y =
			fcppt::literal<T>(
				0.5) *
			(Y + inverse_X);
	}

	return
		X;
}
}
}
}

#endif
