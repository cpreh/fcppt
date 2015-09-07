//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_CONTAINS_HPP_INCLUDED
#define FCPPT_MATH_BOX_CONTAINS_HPP_INCLUDED

#include <fcppt/tag_value.hpp>
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
\brief Test if one box is completely inside another box

\ingroup fcpptmathbox

\param _outer The outer (larger) box

\param _inner The inner (smaller) box
*/
template<
	typename T,
	fcppt::math::size_type N
>
inline
bool
contains(
	fcppt::math::box::object<
		T,
		N
	> const &_outer,
	fcppt::math::box::object<
		T,
		N
	> const &_inner
)
{
	return
		fcppt::algorithm::all_of(
			fcppt::math::int_range_count<
				N
			>{},
			[
				&_outer,
				&_inner
			](
				auto const _index
			)
			{
				auto const index(
					fcppt::tag_value(
						_index
					)
				);

				return
					fcppt::math::at_c<
						index
					>(
						_inner.pos()
					)
					>=
					fcppt::math::at_c<
						index
					>(
						_outer.pos()
					)
					&&
					fcppt::math::at_c<
						index
					>(
						_inner.max()
					)
					<=
					fcppt::math::at_c<
						index
					>(
						_outer.max()
					);
			}
		);
}

}
}
}

#endif
