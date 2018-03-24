//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_REF_RANGE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REF_RANGE_DECL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/container/grid/object_decl.hpp>
#include <fcppt/container/grid/pos_range_impl.hpp>
#include <fcppt/container/grid/pos_ref_iterator_fwd.hpp>
#include <fcppt/container/grid/pos_ref_range_fwd.hpp>
#include <fcppt/container/grid/pos_type.hpp>
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
\brief A range over grid references

\ingroup fcpptcontainergrid
*/
template<
	typename Grid
>
class pos_ref_range
{
public:
	typedef
	fcppt::container::grid::pos_ref_iterator<
		Grid
	>
	iterator;

	typedef
	iterator
	const_iterator;

	typedef
	fcppt::container::grid::pos_range<
		typename
		fcppt::container::grid::pos_type<
			std::remove_cv_t<
				Grid
			>
		>::value_type,
		Grid::static_size::value
	>
	pos_range;

	typedef
	typename
	pos_range::min_type
	min_type;

	typedef
	typename
	pos_range::sup_type
	sup_type;

	typedef
	typename
	pos_range::size_type
	size_type;

	pos_ref_range(
		Grid &,
		min_type,
		sup_type
	);

	iterator
	begin() const;

	iterator
	end() const;

	size_type
	size() const;

	min_type const &
	min() const;

	sup_type const &
	sup() const;
private:
	typedef
	typename
	pos_range::iterator
	pos_iterator;

	iterator
	make_iterator(
		pos_iterator
	) const;

	fcppt::reference<
		Grid
	> grid_;

	pos_range pos_range_;
};

}
}
}

#endif
