//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_NEXT_POSITION_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_NEXT_POSITION_HPP_INCLUDED

#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>


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
fcppt::container::grid::pos<
	SizeType,
	Size
>
next_position(
	fcppt::container::grid::pos<
		SizeType,
		Size
	> const _current,
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
	fcppt::container::grid::pos<
		SizeType,
		Size
	> result{
		_current
	};

	// TODO: Generalize this!
	if(
		++result.x()
		==
		_sup.get().x()
	)
	{
		result.x() = _min.get().x();

		++result.y();
	}

	return
		result;
}

}
}
}

#endif
