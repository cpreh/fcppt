//          Copyright Carl Philipp Reh 2009 - 2016.
//          Copyright Philipp Middendorf 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_INTERSECTS_HPP_INCLUDED
#define FCPPT_MATH_BOX_INTERSECTS_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/math/at_c.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Tests if two boxes intersect

\ingroup fcpptmathbox
*/
template<
	typename T,
	fcppt::math::size_type N
>
inline
bool
intersects(
	fcppt::math::box::object<
		T,
		N
	> const &_a,
	fcppt::math::box::object<
		T,
		N
	> const &_b
)
{
	return
		fcppt::algorithm::all_of(
			fcppt::math::int_range_count<
				N
			>{},
			[
				&_a,
				&_b
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				typedef
				fcppt::tag_type<
					decltype(
						_index
					)
				>
				index;

				return
					fcppt::math::at_c<
						index::value
					>(
						_b.pos()
					)
					<
					fcppt::math::at_c<
						index::value
					>(
						_a.max()
					)
					&&
					fcppt::math::at_c<
						index::value
					>(
						_a.pos()
					)
					<
					fcppt::math::at_c<
						index::value
					>(
						_b.max()
					)
					;
			}
		);
}

}
}
}

#endif
