//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INFINITY_NORM_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INFINITY_NORM_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>
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
*/
template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
T
infinity_norm(
	fcppt::math::matrix::object<
		T,
		R,
		C,
		S
	> const &_matrix
)
{
	// TODO: algorithm
	T maximum_row =
		std::numeric_limits<T>::min();

	for(
		fcppt::math::size_type row =
			0u;
		row < _matrix.rows();
		++row)
	{
		T current_row_sum =
			fcppt::literal<T>(
				0);

		for(
			fcppt::math::size_type column =
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
