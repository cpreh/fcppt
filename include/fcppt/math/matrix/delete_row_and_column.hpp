//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DELETE_ROW_AND_COLUMN_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DELETE_ROW_AND_COLUMN_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/is_static_size.hpp>
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
\param matrix_ The matrix (must be a static matrix)
\param row The row to delete
\param column The column to delete
\return The result type will be <code>(N - 1, M - 1)</code>
*/
template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename boost::enable_if<
	matrix::is_static_size<
		N,
		M
	>,
	typename matrix::static_<
		T,
		N::value-1,
		M::value-1
	>::type const
>::type
delete_row_and_column(
	basic<T, N, M, S> const &matrix_,
	typename basic<T, N, M, S>::size_type const row,
	typename basic<T, N, M, S>::size_type const column
)
{
	typedef typename
	static_<T, N::value-1, M::value-1>::type
	ret_type;

	typedef typename
	ret_type::size_type
	size_type;

	ret_type ret;

	for(
		size_type i =
			static_cast<size_type>(0);
		i < matrix_.rows();
		++i
	)
	{
		if (i == row)
			continue;

		size_type const reali =
			i > row
			?
				static_cast<size_type>(
					i-1)
			: i;

		for(
			size_type j = static_cast<size_type>(0);
			j < matrix_.columns();
			++j
		)
		{
			if (j == column)
				continue;

			size_type const realj =
				j > column
				?
					static_cast<size_type>(j-1)
				:
					j;

			ret[reali][realj] = matrix_[i][j];
		}
	}

	return ret;
}

}
}
}

#endif
