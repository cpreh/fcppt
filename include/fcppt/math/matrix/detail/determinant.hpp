//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_DETERMINANT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_DETERMINANT_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/delete_row_and_column.hpp>
#include <fcppt/math/matrix/has_dim.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template<
	typename T,
	typename S
>
T
determinant(
	fcppt::math::matrix::object<
		T,
		1,
		1,
		S
	> const &_matrix
)
{
	return
		_matrix[0][0];
}

/// Calculates the matrix determinant via the Laplace extension and delete_column_and_row
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
typename
std::enable_if<
	!fcppt::math::matrix::has_dim<
		fcppt::math::matrix::object<
			T,
			N,
			N,
			S
		>,
		1,
		1
	>::value,
	T
>::type
determinant(
	fcppt::math::matrix::object<
		T,
		N,
		N,
		S
	> const &_matrix
)
{
	// TODO: fold?
	T sum = fcppt::literal<T>(0);

	for (size_type i = 0; i < _matrix.columns(); ++i)
	{
		T const coeff =
			i % fcppt::literal<size_type>(2) == fcppt::literal<size_type>(0)
			?
				fcppt::literal<T>(
					1)
			:
				fcppt::literal<T>(
					-1);

		sum +=
			coeff *
			_matrix[i][0] *
			fcppt::math::matrix::detail::determinant(
				fcppt::math::matrix::delete_row_and_column(
					_matrix,
					i,
					0
				)
			);
	}

	return
		sum;
}

}
}
}
}

#endif
