//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MIN_LESS_SUP_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MIN_LESS_SUP_HPP_INCLUDED

#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/range/combine.hpp>
#include <boost/tuple/tuple.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
bool
min_less_sup(
	fcppt::container::grid::min<
		SizeType,
		Size
	> const _min,
	fcppt::container::grid::sup<
		SizeType,
		Size
	> const _sup
)
{
	return
		fcppt::algorithm::all_of(
			boost::range::combine(
				_min.get(),
				_sup.get()
			),
			[](
				boost::tuple<
					fcppt::container::grid::size_type,
					fcppt::container::grid::size_type
				> const _val
			)
			{
				return
					boost::get<
						0
					>(
						_val
					)
					<
					boost::get<
						1
					>(
						_val
					);
			}
		);
}

}
}
}

#endif
