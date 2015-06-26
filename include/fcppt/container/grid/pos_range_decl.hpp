//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_RANGE_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_iterator_fwd.hpp>
#include <fcppt/container/grid/pos_range_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	fcppt::container::grid::size_type Size
>
class pos_range
{
	FCPPT_NONASSIGNABLE(
		pos_range
	);
public:
	typedef
	fcppt::container::grid::pos_iterator<
		Size
	>
	iterator;

	typedef
	typename
	iterator::value_type
	pos;

	typedef
	typename
	iterator::min
	min;

	typedef
	typename
	iterator::sup
	sup;

	pos_range(
		min,
		sup
	);

	iterator
	begin() const;

	iterator
	end() const;

	// TODO: Add size here!
private:
	iterator
	make_iterator(
		pos
	) const;

	min const min_;

	sup const sup_;
};

}
}
}

#endif
