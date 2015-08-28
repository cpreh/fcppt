//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/math/detail/binary_type.hpp>
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

/// Multiplies a matrix by a vector
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
	C
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
		R,
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
				typename
				result_type::size_type const _i
			)
			{
				// TODO: fold?
				auto cur(
					fcppt::literal<
						typename
						result_type::value_type
					>(
						0
					)
				);

				for(
					auto const j
					:
					fcppt::make_int_range_count(
						R
					)
				)
					cur +=
						_left[_i][j]
						*
						_right[j];

				return
					cur;
			}
		);
}

}
}
}

#endif
