//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETERMINANT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETERMINANT_HPP_INCLUDED

#include <fcppt/math/is_static_size.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/detail/determinant.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


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
\param matrix_ The matrix

This function uses the Laplace extension. Consider it slow (very slow!).

\see fcppt::math::matrix::delete_row_and_column.
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
	T
>::type
determinant(
	object<T, N, N, S> const &matrix_
)
{
	return
		matrix::detail::determinant(
			matrix_
		);
}

}
}
}

#endif
