//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ADJUGATE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ADJUGATE_HPP_INCLUDED

#include <fcppt/math/is_static_size.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/delete_row_and_column.hpp>
#include <fcppt/math/matrix/determinant.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Calculates the adjugate matrix
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam N The matrix's row (and column!) dimension type
\tparam S The matrix's storage type
\param matrix_ Must be a statically sized matrix

\warning
You should consider this a slow operation.
*/
template
<
	typename T,
	typename N,
	typename S
>
typename
boost::enable_if
<
	math::is_static_size
	<
		N
	>,
	typename static_
	<
		T,
		N::value,
		N::value
	>::type const
>::type
adjugate(
	matrix::object<T,N,N,S> const &matrix_
)
{
	typedef typename
	static_<T,N::value,N::value>::type
	ret_type;

	ret_type ret;

	for (size_type rows = 0; rows < N::value; ++rows)
	{
		for (size_type cols = 0; cols < N::value; ++cols)
		{
			T const coeff =
				(rows+cols) % static_cast<size_type>(2) == static_cast<size_type>(0)
				?
					static_cast<T>(
						1
					)
				:
					static_cast<T>(
						-1
					);

			// Note: We transpose here because we want the adjugate, not the cofactor
			// matrix
			ret[cols][rows] =
				coeff *
				matrix::determinant(
					matrix::delete_row_and_column(
						matrix_,
						rows,
						cols
					)
				);
		}
	}

	return ret;
}

}
}
}

#endif
