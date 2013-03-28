//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED

#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/detail/linear_access.hpp>
#include <fcppt/math/matrix/normal_storage.hpp>
#include <fcppt/math/matrix/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

#define FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(\
	op\
)\
template<\
	typename L,\
	typename R,\
	typename N,\
	typename M,\
	typename S1,\
	typename S2\
>\
fcppt::math::matrix::object<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
	N,\
	M,\
	typename fcppt::math::matrix::normal_storage<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N,\
		M\
	>::type\
> const \
operator op(\
	fcppt::math::matrix::object<\
		L,\
		N,\
		M,\
		S1\
	> const &_left,\
	fcppt::math::matrix::object<\
		R,\
		N,\
		M,\
		S2\
	> const &_right\
)\
{\
	typedef fcppt::math::matrix::object<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N,\
		M,\
		typename fcppt::math::matrix::normal_storage<\
			FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
			N,\
			M\
		>::type \
	> result_type; \
\
	result_type result(\
		_left.dimension() \
	);\
\
	for(\
		typename result_type::size_type index(\
			0u \
		);\
		index < _left.size();\
		++index\
	) \
		fcppt::math::detail::linear_access(\
			result, \
			index \
		) \
		= \
		fcppt::math::detail::linear_access(\
			_left,\
			index\
		) \
		op \
		fcppt::math::detail::linear_access(\
			_right,\
			index\
		);\
\
	return \
		result; \
}

FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(+)
FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(-)

#undef FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION

template<
	typename L,
	typename R,
	typename N,
	typename M1,
	typename M2,
	typename S1,
	typename S2
>
fcppt::math::matrix::object<
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
	M1,
	M2,
	typename fcppt::math::matrix::normal_storage<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
		M1,
		M2
	>::type
> const
operator *(
	fcppt::math::matrix::object<
		L,
		M1,
		N,
		S1
	> const &_left,
	fcppt::math::matrix::object<
		R,
		N,
		M2,
		S2
	> const &_right
)
{
	typedef fcppt::math::matrix::object<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
		M1,
		M2,
		typename fcppt::math::matrix::normal_storage<
			FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
			M1,
			M2
		>::type
	> result_type;

	result_type ret(
		typename result_type::dim(
			_left.rows(),
			_right.columns()
		)
	);

	for(
		typename
		fcppt::math::matrix::object<
			L,
			M1,
			N,
			S1
		>::size_type i = 0u;
		i < _left.rows();
		++i
	)
		for(
			typename
			fcppt::math::matrix::object<
				R,
				N,
				M2,
				S2
			>::size_type j = 0;
			j < _right.columns();
			++j
		)
		{
			typename result_type::value_type v(0);

			for(
				typename result_type::size_type r = 0;
				r < N::value;
				++r
			)
				v += _left[i][r] * _right[r][j];
			ret[i][j] = v;
		}

	return ret;
}

#define FCPPT_MATH_MAKE_FREE_SCALAR_MATRIX_FUNCTION(\
	op\
) \
template< \
	typename L,\
	typename R,\
	typename N,\
	typename M,\
	typename S\
>\
fcppt::math::matrix::object<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
	N,\
	M,\
	typename fcppt::math::matrix::normal_storage<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N,\
		M\
	>::type\
> const \
operator op(\
	fcppt::math::matrix::object<\
		L,\
		N,\
		M,\
		S\
	> const &_left,\
	R const &_right\
)\
{\
	typedef \
	fcppt::math::matrix::object<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N,\
		M,\
		typename fcppt::math::matrix::normal_storage<\
			FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
			N,\
			M\
		>::type\
	> result_type; \
\
	result_type result(\
		_left.dim()\
	);\
\
	for(\
		typename result_type::size_type index(\
			0u\
		); \
		index < result.size();\
		++index\
	)\
		fcppt::math::detail::linear_access(\
			result,\
			index\
		) \
		= \
		fcppt::math::detail::linear_access(\
			_left,\
			index\
		) \
		op \
		_right; \
\
	return \
		result; \
}

FCPPT_MATH_MAKE_FREE_SCALAR_MATRIX_FUNCTION(
	*
)

FCPPT_MATH_MAKE_FREE_SCALAR_MATRIX_FUNCTION(
	/
)

#undef FCPPT_MATH_MAKE_FREE_SCALAR_MATRIX_FUNCTION

template<
	typename L,
	typename R,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
	N,
	M,
	typename fcppt::math::matrix::normal_storage<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
		N,
		M
	>::type
> const
operator *(
	L const &_left,
	fcppt::math::matrix::object<
		R,
		N,
		M,
		S
	> const &_right
)
{
	typedef
	fcppt::math::matrix::object<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
		N,
		M,
		typename fcppt::math::matrix::normal_storage<
			FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
			N,
			M
		>::type
	> result_type;

	result_type result(
		_right.dimension()
	);

	for(
		typename result_type::size_type index(
			0u
		); 
		index < result.size();
		++index
	)
		fcppt::math::detail::linear_access(
			result,
			index
		)
		=
		_left
		*
		fcppt::math::detail::linear_access(
			_right,
			index
		);

	return
		result;
}

}
}
}

#endif
