//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_LOGARITHM_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_LOGARITHM_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/int_to_float.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/infinity_norm.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/sqrt.hpp>
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
This function is intentionally undocumented as of yet. It needs to be tested
more, and then possibly generalized a bit so e1, e2 and e3 have more meaning to
users.
*/
template
<
	typename T,
	typename DN,
	typename S
>
fcppt::math::matrix::object<T,DN,DN,S> const
logarithm(
	fcppt::math::matrix::object<T,DN,DN,S> A,
	T const e1,
	T const e2,
	T const e3)
{
	static_assert(
		std::is_floating_point<T>::value,
		"logarithm can only be used on floating point types"
	);

	typedef
	fcppt::math::matrix::object<T,DN,DN,S>
	matrix_type;

	typedef typename
	matrix_type::size_type
	matrix_size_type;

	matrix_size_type k =
		0u;

	while(fcppt::math::matrix::infinity_norm(A - matrix_type::identity()) > e1)
	{
		A =
			fcppt::math::matrix::sqrt(
				A,
				e3);
		k++;
	}

	A -=
		matrix_type::identity();

	matrix_type
		Z =
			A,
		X =
			A;

	matrix_size_type i =
		1u;

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

	if(k != fcppt::literal<matrix_size_type>(0))
		X =
			fcppt::cast::int_to_float<
				T
			>(
				fcppt::literal<
					matrix_size_type
				>(
					1u
				)
				<<
				k
			)
			*
			X;

	return
		X;
}
}
}
}

#endif
