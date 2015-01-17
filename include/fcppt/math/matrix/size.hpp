//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_SIZE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_SIZE_HPP_INCLUDED

#include <fcppt/math/matrix/dim.hpp>
#include <fcppt/math/matrix/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief The two-dimensional size of the matrix

Returns the size of the matrix \a _matrix as <code>(columns, rows)</code>

\ingroup fcpptmathmatrix
*/
template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::dim const
size(
	fcppt::math::matrix::object<
		T,
		N,
		M,
		S
	> const &_matrix
)
{
	return
		fcppt::math::matrix::dim(
			_matrix.columns(),
			_matrix.rows()
		);
}

}
}
}

#endif
