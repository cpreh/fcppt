//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OFFSET_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OFFSET_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/int_range.hpp>
#include <fcppt/math/dim/at.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Returns the absolute offset of a position

\ingroup fcpptcontainergrid
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
SizeType
offset(
	fcppt::container::grid::pos<
		SizeType,
		Size
	> const &_pos,
	fcppt::container::grid::dim<
		SizeType,
		Size
	> const &_size
)
{
	FCPPT_MAKE_STRONG_TYPEDEF(
		SizeType,
		result
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		SizeType,
		stacked_dim
	);

	return
		fcppt::algorithm::fold(
			fcppt::math::int_range<
				1u,
				Size
			>{},
			std::make_pair(
				result{
					_pos.x()
				},
				stacked_dim{
					fcppt::literal<
						SizeType
					>(
						1
					)
				}
			),
			[
				&_pos,
				&_size
			](
				auto const _index,
				std::pair<
					result,
					stacked_dim
				> _sum
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

				_sum.second *=
					stacked_dim{
						fcppt::math::dim::at<
							index::value
							-
							1u
						>(
							_size
						)
					};

				_sum.first +=
					result{
						fcppt::math::vector::at<
							index::value
						>(
							_pos
						)
						*
						_sum.second.get()
					};

				return
					_sum;
			}
		).first.get();
}

}
}
}

#endif
