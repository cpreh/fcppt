//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DELETE_ROW_AND_COLUMN_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DELETE_ROW_AND_COLUMN_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/index.hpp>
#include <fcppt/math/matrix/init.hpp>
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

\param _matrix The matrix (must be a static matrix)

\param _row The row to delete

\param _column The column to delete

\return The result type will be <code>(N - 1, M - 1)</code>
*/
template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
fcppt::math::matrix::static_<
	T,
	R
	-
	1u,
	C
	-
	1u
>
delete_row_and_column(
	fcppt::math::matrix::object<
		T,
		R,
		C,
		S
	> const &_matrix,
	fcppt::math::size_type const _row,
	fcppt::math::size_type const _column
)
{
	typedef
	fcppt::math::matrix::static_<
		T,
		R
		-
		1u,
		C
		-
		1u
	>
	result_type;

	return
		fcppt::math::matrix::init<
			result_type
		>(
			[
				&_matrix,
				_row,
				_column
			](
				fcppt::math::matrix::index const _index
			)
			{
				auto const clamp(
					[](
						fcppt::math::size_type const _cur,
						fcppt::math::size_type const _rem
					)
					{
						return
							_cur
							>=
							_rem
							?
								_cur
								+
								fcppt::literal<
									fcppt::math::size_type
								>(
									1
								)
							:
								_cur
							;
					}
				);

				return
					_matrix[
						clamp(
							_index.row(),
							_row
						)
					][
						clamp(
							_index.column(),
							_column
						)
					];
			}
		);
}

}
}
}

#endif
