//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED

#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/// Multiplies a matrix by a vector
template<
	typename L,
	typename R,
	typename N,
	typename M,
	typename S1,
	typename S2
>
fcppt::math::vector::object<
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
	M,
	typename fcppt::math::static_storage<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
		M
	>::type
>
operator *(
	fcppt::math::matrix::object<
		L,
		N,
		M,
		S1
	> const &_left,
	fcppt::math::vector::object<
		R,
		N,
		S2
	> const &_right
)
{
	typedef fcppt::math::vector::object<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
		M,
		typename fcppt::math::static_storage<
			FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
			M
		>::type
	> result_type;

	result_type result(
		result_type::null()
	);

	for(
		typename result_type::size_type i = 0;
		i < result.size();
		++i
	)
		for(
			typename
			fcppt::math::matrix::object<
				L,
				N,
				M,
				S2
			>::size_type j = 0;
			j < _right.size();
			++j
		)
			result[i] += _left[i][j] * _right[j];

	return result;
}

}
}
}

#endif
