//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_RANGE_DECL_HPP_INCLUDED

#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_iterator_fwd.hpp>
#include <fcppt/container/grid/pos_range_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/type_traits/value_type.hpp>
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
	using
	iterator
	=
	fcppt::container::grid::pos_iterator<
		SizeType,
		Size
	>;

	using
	const_iterator
	=
	iterator;

	using
	pos
	=
	fcppt::type_traits::value_type<
		iterator
	>;

	using
	min_type
	=
	typename
	iterator::min;

	using
	sup_type
	=
	typename
	iterator::sup;

	pos_range(
		min_type,
		sup_type
	);

	[[nodiscard]]
	iterator
	begin() const;

	[[nodiscard]]
	iterator
	end() const;

	using
	size_type
	=
	std::make_unsigned_t<
		typename
		iterator::difference_type
	>;

	[[nodiscard]]
	size_type
	size() const;

	[[nodiscard]]
	min_type const &
	min() const;

	[[nodiscard]]
	sup_type const &
	sup() const;
private:
	[[nodiscard]]
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
