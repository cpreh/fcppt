//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED
#define FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED

#include <fcppt/make_homogenous_pair.hpp>
#include <fcppt/math/at_c.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/init.hpp>
#include <fcppt/math/box/intersects.hpp>
#include <fcppt/math/box/max_at_c.hpp>
#include <fcppt/math/box/null.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Calculates the intersection of two boxes (which is, again, a box)
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>

If there is no intersection, the null box will be returned.
*/
template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::object<
	T,
	N
>
intersection(
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
	typedef
	fcppt::math::box::object<
		T,
		N
	>
	result_type;

	return
		fcppt::math::box::intersects(
			_a,
			_b
		)
		?
			fcppt::math::box::init<
				result_type
			>(
				[
					&_a,
					&_b
				](
					auto const _index
				)
				{
					T const pos(
						std::max(
							fcppt::math::at_c<
								_index
							>(
								_a.pos()
							),
							fcppt::math::at_c<
								_index
							>(
								_b.pos()
							)
						)
					);

					return
						fcppt::make_homogenous_pair(
							pos,
							std::min(
								fcppt::math::box::max_at_c<
									_index
								>(
									_a
								),
								fcppt::math::box::max_at_c<
									_index
								>(
									_b
								)
							)
							-
							pos
						);
				}
			)
		:
			fcppt::math::box::null<
				result_type
			>()
		;
}

}
}
}

#endif
