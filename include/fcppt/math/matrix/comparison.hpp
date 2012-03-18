//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_COMPARISON_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_COMPARISON_HPP_INCLUDED

#include <fcppt/math/detail/array_equal.hpp>
#include <fcppt/math/matrix/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Compares two matrices component-wise
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam M The matrix's row dimension type
\tparam N The matrix's column dimension type
\tparam S1 The first matrix's storage type
\tparam S2 The second matrix's storage type
\param v1 The first matrix
\param v2 The second matrix

\warning
This uses <code>T</code>'s equality comparison operator, so be careful if you
want to compare floating point matrices.
*/
template<
	typename T,
	typename N,
	typename M,
	typename S1,
	typename S2
>
bool
operator==(
	object<T, N, M, S1> const &v1,
	object<T, N, M, S2> const &v2
)
{
	return
		fcppt::math::detail::array_equal(
			v1,
			v2
		);
}

/**
\brief Compares two matrices component-wise
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam M The matrix's row dimension type
\tparam N The matrix's column dimension type
\tparam S1 The first matrix's storage type
\tparam S2 The second matrix's storage type
\param v1 The first matrix
\param v2 The second matrix

\warning
This uses <code>T</code>'s inequality comparison operator, so be careful if you
want to compare floating point matrices.
*/
template<
	typename T,
	typename N,
	typename M,
	typename S1,
	typename S2
>
bool
operator!=(
	object<T, N, M, S1> const &v1,
	object<T, N, M, S2> const &v2
)
{
	return
		!(v1 == v2);
}

}
}
}

#endif
