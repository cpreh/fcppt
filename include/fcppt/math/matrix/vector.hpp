//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/vector/init.hpp>
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
	fcppt::math::static_storage<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
		M
	>
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
	typedef
	fcppt::math::vector::object<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
		M,
		fcppt::math::static_storage<
			FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
			M
		>
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
						N::value
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
