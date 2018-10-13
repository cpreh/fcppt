//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_SPIRAL_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_SPIRAL_RANGE_DECL_HPP_INCLUDED

#include <fcppt/container/grid/spiral_iterator_fwd.hpp>
#include <fcppt/container/grid/spiral_range_fwd.hpp>
#include <fcppt/type_traits/value_type.hpp>


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
public:
	static_assert(
		Pos::dim_wrapper::value
		== 2,
		"Sorry, this only works with two dimensional grids for now"
	);

	typedef
	fcppt::type_traits::value_type<
		Pos
	>
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
	Pos start_;

	value_type dist_;
};

}
}
}

#endif
