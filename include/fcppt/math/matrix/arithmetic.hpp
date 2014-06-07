//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED

#include <fcppt/no_init.hpp>
#include <fcppt/math/binary_map.hpp>
#include <fcppt/math/map.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/detail/linear_access.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static_storage.hpp>


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
	fcppt::math::matrix::static_storage<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N,\
		M\
	>\
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
	typedef \
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R)\
	result_value_type;\
\
	return \
		fcppt::math::binary_map<\
			fcppt::math::matrix::object<\
				result_value_type,\
				N,\
				M,\
				fcppt::math::matrix::static_storage<\
					result_value_type,\
					N,\
					M\
				>\
			> \
		>(\
			_left,\
			_right,\
			[](\
				L const &_left_elem,\
				R const &_right_elem\
			)\
			{\
				return \
					_left_elem \
					op \
					_right_elem;\
			}\
		);\
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
	fcppt::math::matrix::static_storage<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
		M1,
		M2
	>
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
		fcppt::math::matrix::static_storage<
			FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
			M1,
			M2
		>
	> result_type;

	result_type ret{
		fcppt::no_init()
	};

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
	fcppt::math::matrix::static_storage<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N,\
		M\
	>\
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
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R)\
	result_value_type;\
\
	return \
		fcppt::math::map<\
			fcppt::math::matrix::object<\
				result_value_type,\
				N,\
				M,\
				fcppt::math::matrix::static_storage<\
					result_value_type,\
					N,\
					M\
				>\
			>\
		>(\
			_left,\
			[\
				&_right\
			](\
				L const &_left_element\
			)\
			{\
				_left_element \
				op \
				_right;\
			}\
		);\
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
	fcppt::math::matrix::static_storage<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
		N,
		M
	>
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
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R)
	result_value_type;

	return
		fcppt::math::map<
			fcppt::math::matrix::object<
				result_value_type,
				N,
				M,
				fcppt::math::matrix::static_storage<
					result_value_type,
					N,
					M
				>
			>
		>(
			_right,
			[
				&_left
			](
				R const &_right_elem
			)
			{
				return
					_left
					*
					_right_elem;
			}
		);
}

}
}
}

#endif
