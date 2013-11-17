//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_SPIRAL_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_SPIRAL_RANGE_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/container/grid/spiral_iterator_fwd.hpp>
#include <fcppt/container/grid/spiral_range_fwd.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename Pos
>
class spiral_range
{
	FCPPT_NONASSIGNABLE(
		spiral_range
	);
public:
	static_assert(
		Pos::dim_wrapper::value
		== 2,
		"Sorry, this only works with two dimensional grids for now"
	);

	typedef
	typename
	Pos::value_type
	value_type;

	spiral_range(
		Pos start,
		value_type dist
	);

	typedef
	fcppt::container::grid::spiral_iterator<
		Pos
	>
	iterator;

	iterator
	begin() const;

	iterator
	end() const;
private:
	Pos const start_;

	value_type const dist_;
};

}
}
}

#endif
