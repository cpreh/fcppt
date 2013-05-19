#ifndef FCPPT_CONTAINER_GRID_POS_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_RANGE_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/object_decl.hpp>
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
	Grid::dim
	dim;

	typedef
	fcppt::container::grid::pos_iterator<
		Grid
	>
	iterator;

	pos_range(
		Grid &,
		dim const &start,
		dim const &end
	);

	iterator
	begin() const;

	iterator
	end() const;
private:
	iterator
	make_iterator(
		dim const &pos,
		bool is_end
	) const;

	Grid &grid_;

	dim const start_;

	dim const end_;
};

}
}
}

#endif
