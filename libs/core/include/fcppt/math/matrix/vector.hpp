//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/matrix/at_r_c.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/value_type.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Multiplies a matrix by a vector

\ingroup fcpptmathmatrix
*/
template<
	typename Left,
	typename Right,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S1,
	typename S2
>
fcppt::math::vector::static_<
	FCPPT_MATH_DETAIL_BINARY_TYPE(Left, *, Right),
	R
>
operator *(
	fcppt::math::matrix::object<
		Left,
		R,
		C,
		S1
	> const &_left,
	fcppt::math::vector::object<
		Right,
		C,
		S2
	> const &_right
)
{
	typedef
	fcppt::math::vector::static_<
		FCPPT_MATH_DETAIL_BINARY_TYPE(Left, *, Right),
		R
	>
	result_type;

	return
		fcppt::math::vector::init<
			result_type
		>(
			[
				&_left,
				&_right
			](
				auto const _row
			)
			{
				typedef
				fcppt::type_traits::value_type<
					result_type
				>
				value_type;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)
				return
					fcppt::algorithm::fold(
						fcppt::math::int_range_count<
							C
						>{},
						fcppt::literal<
							value_type
						>(
							0
						),
						[
							&_left,
							&_right,
							_row
						](
							auto const _column,
							value_type const _sum
						)
						{
							FCPPT_USE(
								_column
							);

							FCPPT_USE(
								_row
							);

							typedef
							fcppt::tag_type<
								decltype(
									_column
								)
							>
							column;

							typedef
							decltype(
								_row
							)
							row;

							return
								_sum
								+
								fcppt::math::matrix::at_r_c<
									row::value,
									column::value
								>(
									_left
								)
								*
								fcppt::math::vector::at<
									column::value
								>(
									_right
								);
						}
					);
FCPPT_PP_POP_WARNING
			}
		);
}

}
}
}

#endif
