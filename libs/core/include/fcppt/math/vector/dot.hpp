//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DOT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DOT_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculates the dot product of two vectors

\ingroup fcpptmathvector

The dot product is defined here:

http://en.wikipedia.org/wiki/Dot_product
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
T
dot(
	fcppt::math::vector::object<
		T,
		N,
		S1
	> const &_left,
	fcppt::math::vector::object<
		T,
		N,
		S2
	> const &_right
)
{
	return
		fcppt::algorithm::fold(
			fcppt::math::int_range_count<
				N
			>{},
			fcppt::literal<
				T
			>(
				0
			),
			[
				&_left,
				&_right
			](
				auto const _index,
				T const _sum
			)
			{
				FCPPT_USE(
					_index
				);

				using
				index
				=
				fcppt::tag_type<
					decltype(
						_index
					)
				>;

				return
					_sum
					+
					fcppt::math::vector::at<
						index::value
					>(
						_left
					)
					*
					fcppt::math::vector::at<
						index::value
					>(
						_right
					);
			}
		);
}

}
}
}

#endif
