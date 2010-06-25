//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETERMINANT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETERMINANT_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/detail/determinant.hpp>
#include <fcppt/math/is_static_size.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

/// Calculates the matrix determinant
/**
 * Uses the Laplace extension and delete_column_and_row.
 * @param matrix_ must be a statically sized matrix
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
	basic<T, N, N, S> const &matrix_
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
