//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DELETE_ROW_AND_COLUMN_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DELETE_ROW_AND_COLUMN_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Deletes a specific row and rolumn (a cross) from the matrix
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam M The matrix's row dimension type
\tparam N The matrix's column dimension type
\tparam S The matrix's storage type
\param _matrix The matrix (must be a static matrix)
\param _row The row to delete
\param _column The column to delete
\return The result type will be <code>(N - 1, M - 1)</code>
*/
template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::static_<
	T,
	N::value-1,
	M::value-1
> const
delete_row_and_column(
	fcppt::math::matrix::object<T, N, M, S> const &_matrix,
	typename object<T, N, M, S>::size_type const _row,
	typename object<T, N, M, S>::size_type const _column
)
{
	typedef
	fcppt::math::matrix::static_<
		T,
		N::value
		-
		1,
		M::value
		-
		1
	>
	ret_type;

	typedef typename
	ret_type::size_type
	size_type;

	ret_type ret{
		fcppt::no_init()
	};

	for(
		size_type i =
			fcppt::literal<size_type>(0);
		i < _matrix.rows();
		++i
	)
	{
		if (i == _row)
			continue;

		size_type const reali =
			i > _row
			?
				i
				-
				fcppt::literal<size_type>(
					1
				)
			: i;

		for(
			size_type j = fcppt::literal<size_type>(0);
			j < _matrix.columns();
			++j
		)
		{
			if (j == _column)
				continue;

			size_type const realj =
				j > _column
				?
					j - fcppt::literal<size_type>(1)
				:
					j;

			ret[reali][realj] = _matrix[i][j];
		}
	}

	return ret;
}

}
}
}

#endif
