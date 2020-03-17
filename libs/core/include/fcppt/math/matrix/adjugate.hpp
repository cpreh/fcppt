//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ADJUGATE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ADJUGATE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/delete_row_and_column.hpp>
#include <fcppt/math/matrix/determinant.hpp>
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
\brief Calculates the adjugate matrix
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam N The matrix's row (and column!) dimension type
\tparam S The matrix's storage type
\param _matrix Must be a statically sized matrix

\warning
You should consider this a slow operation.
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
fcppt::math::matrix::static_<
	T,
	N,
	N
>
adjugate(
	fcppt::math::matrix::object<
		T,
		N,
		N,
		S
	> const &_matrix
)
{
	using
	result_type
	=
	fcppt::math::matrix::static_<
		T,
		N,
		N
	>;

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
				T const coeff{
					(
						_index.row()
						+
						_index.column()
					)
					%
					fcppt::literal<
						fcppt::math::size_type
					>(
						2
					)
					==
					fcppt::literal<
						fcppt::math::size_type
					>(
						0
					)
					?
						fcppt::literal<
							T
						>(
							1
						)
					:
						fcppt::literal<
							T
						>(
							-1
						)
				};

				// Note: We transpose here because we want the adjugate, not the cofactor
				// matrix
				return
					coeff
					*
					fcppt::math::matrix::determinant(
						fcppt::math::matrix::delete_row_and_column<
							_index.column(),
							_index.row()
						>(
							_matrix
						)
					);
			}
		);
}

}
}
}

#endif
