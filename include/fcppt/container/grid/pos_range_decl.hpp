//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_RANGE_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/container/grid/object_decl.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_iterator_fwd.hpp>
#include <fcppt/container/grid/pos_range_fwd.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename Grid
>
class pos_range
{
	FCPPT_NONASSIGNABLE(
		pos_range
	);
public:
	static_assert(
		Grid::dim::dim_wrapper::value
		== 2,
		"Sorry, this only works with two dimensional grids for now"
	);

	typedef
	typename
	Grid::pos
	pos;

	typedef
	fcppt::container::grid::pos_iterator<
		Grid
	>
	iterator;

	pos_range(
		Grid &,
		pos const &start,
		pos const &end
	);

	iterator
	begin() const;

	iterator
	end() const;
private:
	iterator
	make_iterator(
		pos const &,
		bool is_end
	) const;

	Grid &grid_;

	pos const start_;

	pos const end_;
};

}
}
}

#endif
