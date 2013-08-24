//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_EXPONENTIAL_PADE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_EXPONENTIAL_PADE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/int_to_float.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/infinity_norm.hpp>
#include <fcppt/math/matrix/inverse.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <algorithm>
#include <cmath>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Calculates the matrix exponential e^A using a Pade approximation
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam DN The matrix's row and column dimension type
\tparam S The matrix's storage type
\param _matrix The input matrix
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
	std::is_floating_point<T>,
	fcppt::math::matrix::object<T,DN,DN,S> const
>::type
exponential_pade(
	fcppt::math::matrix::object<T,DN,DN,S> _matrix)
{
	typedef
	fcppt::math::matrix::object<T,DN,DN,S>
	matrix_type;

	typedef typename
	matrix_type::size_type
	matrix_size_type;

	T const
		zero =
			fcppt::literal<T>(
				0),
		one =
			fcppt::literal<T>(
				1),
		two =
			fcppt::literal<T>(
				2);

	T const j(
		std::max(
			zero,
			one +
			std::log(
				fcppt::math::matrix::infinity_norm(
					_matrix)) /
			std::log(
				two)));

	_matrix =
		std::pow(
			two,
			std::floor(
				-j
			)
		)
		*
		_matrix;

	matrix_type
		D =
			matrix_type::identity(),
		N =
			matrix_type::identity(),
		X =
			matrix_type::identity();

	T c =
		fcppt::literal<T>(
			1);

	matrix_size_type const q =
		6u;

	for(
		matrix_size_type k =
			1u;
		k < q;
		++k)
	{
		T const
			qf =
				fcppt::cast::int_to_float<T>(
					q),
			kf =
				fcppt::cast::int_to_float<T>(
					k);
		c =
			(c*(qf-kf+one))/
			(kf*(two*qf-kf+one));

		X =
			_matrix * X;

		matrix_type const cX =
			c * X;

		N +=
			cX;

		D +=
			(k % 2u == 0u ? fcppt::literal<T>(1) : fcppt::literal<T>(-1)) *
			cX;
	}

	X =
		fcppt::math::matrix::inverse(
			D) *
		N;

	matrix_type result =
		X;

	for(
		matrix_size_type i = 0u;
		i < j;
		++i)
		result =
			result * result;

	return
		result;
}
}
}
}

#endif
