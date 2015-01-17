//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INFINITY_NORM_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INFINITY_NORM_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <cmath>
#include <limits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Calculates the infinity norm
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam N The matrix's row dimension type
\tparam M The matrix's column dimension type
\tparam S The matrix's storage type
\param _matrix The input matrix
*/
template
<
	typename T,
	typename N,
	typename M,
	typename S
>
T
infinity_norm(
	fcppt::math::matrix::object<T,N,M,S> const &_matrix)
{
	typedef
	fcppt::math::matrix::object<T,N,M,S>
	matrix_type;

	typedef typename
	matrix_type::size_type
	matrix_size_type;

	T maximum_row =
		std::numeric_limits<T>::min();

	for(
		matrix_size_type row =
			0u;
		row < _matrix.rows();
		++row)
	{
		T current_row_sum =
			fcppt::literal<T>(
				0);

		for(
			matrix_size_type column =
				0u;
			column < _matrix.columns();
			++column)
			current_row_sum +=
				std::abs(
					_matrix[row][column]);

		maximum_row =
			std::max(
				current_row_sum,
				maximum_row);
	}

	return
		maximum_row;
}
}
}
}

#endif
