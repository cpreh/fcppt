//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_REF_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REF_RANGE_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/container/grid/object_decl.hpp>
#include <fcppt/container/grid/pos_range_impl.hpp>
#include <fcppt/container/grid/pos_ref_range_fwd.hpp>
#include <fcppt/container/grid/pos_ref_iterator_fwd.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename Grid
>
class pos_ref_range
{
	FCPPT_NONASSIGNABLE(
		pos_ref_range
	);
public:
	typedef
	fcppt::container::grid::pos_ref_iterator<
		Grid
	>
	iterator;

	typedef
	fcppt::container::grid::pos_range<
		typename
		Grid::pos::value_type,
		Grid::static_size::value
	>
	pos_range;

	typedef
	typename
	pos_range::min
	min;

	typedef
	typename
	pos_range::sup
	sup;

	pos_ref_range(
		Grid &,
		min,
		sup
	);

	iterator
	begin() const;

	iterator
	end() const;

	// TODO: Add size here!
private:
	typedef
	typename
	pos_range::iterator
	pos_iterator;

	iterator
	make_iterator(
		pos_iterator
	) const;

	Grid &grid_;

	pos_range const pos_range_;
};

}
}
}

#endif
