//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETERMINANT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETERMINANT_HPP_INCLUDED

#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/detail/determinant.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Calculates the determinant of a matrix
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam N The matrix's row (and column!) dimension type
\tparam S The matrix's storage type
\param _matrix The matrix

This function uses the Laplace extension. Consider it slow (very slow!).

\see fcppt::math::matrix::delete_row_and_column.
*/
template
<
	typename T,
	typename N,
	typename S
>
T
determinant(
	fcppt::math::matrix::object<
		T,
		N,
		N,
		S
	> const &_matrix
)
{
	return
		fcppt::math::matrix::detail::determinant(
			_matrix
		);
}

}
}
}

#endif
