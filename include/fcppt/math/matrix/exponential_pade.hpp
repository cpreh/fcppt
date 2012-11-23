//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_EXPONENTIAL_PADE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_EXPONENTIAL_PADE_HPP_INCLUDED

#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/infinity_norm.hpp>
#include <fcppt/math/matrix/inverse.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <algorithm>
#include <cmath>
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
\tparam N The matrix's row and column dimension type
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
	boost::is_floating_point<T>,
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
			static_cast<T>(
				0),
		one =
			static_cast<T>(
				1),
		two =
			static_cast<T>(
				2);

	matrix_size_type j =
		static_cast<matrix_size_type>(
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
			-static_cast<T>(
				j)) *
		_matrix;

	matrix_type
		D =
			matrix_type::identity(),
		N =
			matrix_type::identity(),
		X =
			matrix_type::identity();

	T c =
		static_cast<T>(
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
				static_cast<T>(
					q),
			kf =
				static_cast<T>(
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
			(k % 2u == 0u ? static_cast<T>(1) : static_cast<T>(-1)) *
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
