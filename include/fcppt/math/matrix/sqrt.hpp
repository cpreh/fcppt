//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_SQRT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_SQRT_HPP_INCLUDED

#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/infinity_norm.hpp>
#include <fcppt/math/matrix/inverse.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
/*
Calculates the square root of a matrix. This function is intentionally not part
of the public fcppt API. It needs to be tested more, and maybe generalized so
that "epsilon" is more meaningful to users.
*/
template
<
	typename T,
	typename DN,
	typename S
>
typename
boost::enable_if
<
	boost::is_floating_point<T>,
	fcppt::math::matrix::object<T,DN,DN,S> const
>::type
sqrt(
	fcppt::math::matrix::object<T,DN,DN,S> const &_matrix,
	T const epsilon)
{
	typedef
	fcppt::math::matrix::object<T,DN,DN,S>
	matrix_type;

	matrix_type
		X =
			_matrix,
		Y =
			matrix_type::identity();

	while(fcppt::math::matrix::infinity_norm(X * X - _matrix) > epsilon)
	{
		matrix_type const inverse_X =
			fcppt::math::matrix::inverse(
				X);

		X =
			static_cast<T>(
				0.5) *
			(X + fcppt::math::matrix::inverse(Y));

		Y =
			static_cast<T>(
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
