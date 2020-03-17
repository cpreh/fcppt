//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_LOGARITHM_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_LOGARITHM_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/int_to_float.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/identity.hpp>
#include <fcppt/math/matrix/infinity_norm.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/sqrt.hpp>
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
This function is intentionally undocumented as of yet. It needs to be tested
more, and then possibly generalized a bit so e1, e2 and e3 have more meaning to
users.
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
logarithm(
	fcppt::math::matrix::object<
		T,
		N,
		N,
		S
	> A,
	T const e1,
	T const e2,
	T const e3
)
{
	static_assert(
		std::is_floating_point_v<
			T
		>,
		"logarithm can only be used on floating point types"
	);

	using
	matrix_type
	=
	fcppt::math::matrix::static_<
		T,
		N,
		N
	>;

	fcppt::math::size_type k{
		0U
	};

	while(
		fcppt::math::matrix::infinity_norm(
			A
			-
			fcppt::math::matrix::identity<
				matrix_type
			>()
		)
		>
		e1
	)
	{
		A =
			fcppt::math::matrix::sqrt(
				A,
				e3
			);
		k++;
	}

	A -=
		fcppt::math::matrix::identity<
			matrix_type
		>();

	matrix_type Z{
		A
	};

	matrix_type X{
		A
	};

	fcppt::math::size_type i{
		1U
	};

	while(fcppt::math::matrix::infinity_norm(Z) > e2)
	{
		Z =
			Z * A;
		++i;
		X =
			X +
			fcppt::literal<T>(1)/fcppt::cast::int_to_float<T>(i) *
			Z;
	}

	if(k != fcppt::literal<fcppt::math::size_type>(0))
	{
		X =
			fcppt::cast::int_to_float<
				T
			>(
				fcppt::literal<
					fcppt::math::size_type
				>(
					1U
				)
				<<
				k
			)
			*
			X;
	}

	return
		X;
}

}
}
}

#endif
