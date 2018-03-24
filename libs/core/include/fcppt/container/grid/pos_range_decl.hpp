//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_RANGE_DECL_HPP_INCLUDED

#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_iterator_fwd.hpp>
#include <fcppt/container/grid/pos_range_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief A range over grid position

\ingroup fcpptcontainergrid
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
class pos_range
{
public:
	typedef
	fcppt::container::grid::pos_iterator<
		SizeType,
		Size
	>
	iterator;

	typedef
	iterator
	const_iterator;

	typedef
	typename
	iterator::value_type
	pos;

	typedef
	typename
	iterator::min
	min_type;

	typedef
	typename
	iterator::sup
	sup_type;

	pos_range(
		min_type,
		sup_type
	);

	iterator
	begin() const;

	iterator
	end() const;

	typedef
	std::make_unsigned_t<
		typename
		iterator::difference_type
	>
	size_type;

	size_type
	size() const;

	min_type const &
	min() const;

	sup_type const &
	sup() const;
private:
	iterator
	make_iterator(
		pos
	) const;

	min_type min_;

	sup_type sup_;
};

}
}
}

#endif
