//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INIT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INIT_HPP_INCLUDED

#include <fcppt/math/detail/init.hpp>
#include <fcppt/math/matrix/index.hpp>
#include <fcppt/math/matrix/is_matrix.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Initializes a matrix

\ingroup fcpptmathmatrix

Calls <code>_function</code> for every index of the matrix.

\tparam Matrix Must be a matrix

\tparam Function Must be a function of type <code>Matrix::value_type
(fcppt::math::matrix::index<Matrix::size_type>)</code>
*/
template<
	typename Matrix,
	typename Function
>
inline
Matrix
init(
	Function const &_function
)
{
	static_assert(
		fcppt::math::matrix::is_matrix<
			Matrix
		>::value,
		"Matrix must be a matrix"
	);

	return
		fcppt::math::detail::init<
			Matrix
		>(
			[
				&_function
			](
				typename
				Matrix::size_type const _absolute
			)
			{
				typedef
				fcppt::math::matrix::index<
					typename
					Matrix::size_type
				>
				index_type;

				return
					_function(
						index_type{
							typename
							index_type::row_t{
								_absolute
								/
								Matrix::m_wrapper::value
							}
							,
							typename
							index_type::column_t{
								_absolute
								%
								Matrix::m_wrapper::value
							}
						}
					);
			}
		);
}

}
}
}

#endif
