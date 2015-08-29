//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/math/at_c.hpp>
#include <fcppt/math/binary_map.hpp>
#include <fcppt/math/map.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/matrix/init.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>


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
	typename Left,\
	typename Right,\
	fcppt::math::size_type R,\
	fcppt::math::size_type C,\
	typename S1,\
	typename S2\
>\
fcppt::math::matrix::static_<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(Left, op, Right),\
	R,\
	C \
> \
operator op(\
	fcppt::math::matrix::object<\
		Left,\
		R,\
		C,\
		S1\
	> const &_left,\
	fcppt::math::matrix::object<\
		Right,\
		R,\
		C,\
		S2\
	> const &_right\
)\
{\
	typedef \
	FCPPT_MATH_DETAIL_BINARY_TYPE(Left, op, Right)\
	result_value_type;\
\
	return \
		fcppt::math::binary_map<\
			fcppt::math::matrix::static_<\
				result_value_type,\
				R,\
				C\
			> \
		>(\
			_left,\
			_right,\
			[](\
				Left const &_left_elem,\
				Right const &_right_elem\
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
	fcppt::math::size_type N,
	fcppt::math::size_type M1,
	fcppt::math::size_type M2,
	typename S1,
	typename S2
>
fcppt::math::matrix::static_<
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
	M1,
	M2
>
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
	typedef
	fcppt::math::matrix::static_<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
		M1,
		M2
	>
	result_type;

	typedef
	typename
	result_type::value_type
	value_type;

	return
		fcppt::math::matrix::init<
			result_type
		>(
			[
				&_left,
				&_right
			](
				auto const _index
			)
			{
				return
					fcppt::algorithm::fold(
						fcppt::make_int_range_count(
							N
						),
						fcppt::literal<
							value_type
						>(
							0
						),
						[
							_index,
							&_left,
							&_right
						](
							fcppt::math::size_type const _r,
							value_type const _sum
						)
						{
							// TODO: Make _r a constant
							return
								_sum
								+
								fcppt::math::at_c<
									_index.row()
								>(
									_left
								)[
									_r
								]
								*
								fcppt::math::at_c<
									_index.column()
								>(
									_right[
										_r
									]
								);
						}
					);
			}
		);
}

#define FCPPT_MATH_MAKE_FREE_SCALAR_MATRIX_FUNCTION(\
	op\
) \
template< \
	typename Left,\
	typename Right,\
	fcppt::math::size_type R,\
	fcppt::math::size_type C,\
	typename S\
>\
fcppt::math::matrix::static_<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(Left, op, Right),\
	R,\
	C\
> \
operator op(\
	fcppt::math::matrix::object<\
		Left,\
		R,\
		C,\
		S\
	> const &_left,\
	Right const &_right\
)\
{\
	typedef \
	FCPPT_MATH_DETAIL_BINARY_TYPE(Left, op, Right)\
	result_value_type;\
\
	return \
		fcppt::math::map<\
			fcppt::math::matrix::static_<\
				result_value_type,\
				R,\
				C\
			>\
		>(\
			_left,\
			[\
				&_right\
			](\
				Left const &_left_element\
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
	typename Left,
	typename Right,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
fcppt::math::matrix::static_<
	FCPPT_MATH_DETAIL_BINARY_TYPE(Left, *, Right),
	R,
	C
>
operator *(
	Left const &_left,
	fcppt::math::matrix::object<
		Right,
		R,
		C,
		S
	> const &_right
)
{
	typedef
	FCPPT_MATH_DETAIL_BINARY_TYPE(Left, *, Right)
	result_value_type;

	return
		fcppt::math::map<
			fcppt::math::matrix::static_<
				result_value_type,
				R,
				C
			>
		>(
			_right,
			[
				&_left
			](
				Right const &_right_elem
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
