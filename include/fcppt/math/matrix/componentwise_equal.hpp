//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_COMPONENTWISE_EQUAL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_COMPONENTWISE_EQUAL_HPP_INCLUDED

#include <fcppt/math/detail/array_componentwise_equal.hpp>
#include <fcppt/math/matrix/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Compares two floating point matrices componentwise using an epsilon
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code> (must be a floating point type)
\tparam M The matrix's row dimension type
\tparam N The matrix's column dimension type
\tparam S1 The first matrix's storage type
\tparam S2 The second matrix's storage type
\param _v1 The first matrix
\param _v2 The second matrix
\param _epsilon The epsilon to compare with
*/
template<
	typename T,
	typename N,
	typename M,
	typename S1,
	typename S2
>
bool
componentwise_equal(
	matrix::object<
		T,
		N,
		M,
		S1
	> const &_v1,
	matrix::object<
		T,
		N,
		M,
		S2
	> const &_v2,
	T const _epsilon
)
{
	return
		math::detail::array_componentwise_equal(
			_v1,
			_v2,
			_epsilon
		);
}

}
}
}

#endif
