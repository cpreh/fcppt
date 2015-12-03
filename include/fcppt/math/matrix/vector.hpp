//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/tag_value.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/math/at_c.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/matrix/at_c.hpp>
#include <fcppt/math/matrix/index.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>


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
		C
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
				typename
				result_type::value_type
				value_type;

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
							return
								_sum
								+
								fcppt::math::matrix::at_c(
									_left,
									fcppt::math::matrix::index<
										_row,
										fcppt::tag_value(
											_column
										)
									>{}
								)
								*
								fcppt::math::at_c<
									fcppt::tag_value(
										_column
									)
								>(
									_right
								);
						}
					);
			}
		);
}

}
}
}

#endif
