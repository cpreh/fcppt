//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DELETE_ROW_AND_COLUMN_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DELETE_ROW_AND_COLUMN_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/at_r_c.hpp>
#include <fcppt/math/matrix/init.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/detail/deleted_index.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Deletes a specific row and rolumn (a cross) from the matrix

\ingroup fcpptmathmatrix

\return The result type will be <code>(N - 1, M - 1)</code>

\tparam DR The index of the row to delete
\tparam DC The index of the column to delete
*/
template<
	fcppt::math::size_type DR,
	fcppt::math::size_type DC,
	typename T,
	typename S,
	fcppt::math::size_type R,
	fcppt::math::size_type C
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
	> const &_matrix
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
				&_matrix
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				return
					fcppt::math::matrix::at_r_c<
						fcppt::math::matrix::detail::deleted_index(
							_index.row(),
							DR
						),
						fcppt::math::matrix::detail::deleted_index(
							_index.column(),
							DC
						)
					>(
						_matrix
					);
			}
		);
}

}
}
}

#endif
