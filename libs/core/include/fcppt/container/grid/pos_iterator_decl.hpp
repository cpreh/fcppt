//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_iterator_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/container/grid/detail/pos_iterator_base.hpp>
#include <fcppt/iterator/base_decl.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/type_traits/value_type.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief An iterator over grid position

\ingroup fcpptcontainergrid
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
class pos_iterator final
:
	public
		fcppt::container::grid::detail::pos_iterator_base<
			SizeType,
			Size
		>
{
	typedef
	fcppt::container::grid::detail::pos_iterator_base<
		SizeType,
		Size
	>
	base_type;
public:
	typedef
	fcppt::type_traits::value_type<
		base_type
	>
	value_type;

	typedef
	value_type
	pos;

	typedef
	fcppt::type_traits::value_type<
		pos
	>
	size_type;

	typedef
	typename
	base_type::reference
	reference;

	typedef
	typename
	base_type::pointer
	pointer;

	typedef
	typename
	base_type::iterator_category
	iterator_category;

	typedef
	typename
	base_type::difference_type
	difference_type;

	typedef
	fcppt::container::grid::min<
		size_type,
		Size
	>
	min;

	typedef
	fcppt::container::grid::sup<
		size_type,
		Size
	>
	sup;

	pos_iterator(
		pos,
		min,
		sup
	);

	void
	increment();

	reference
	dereference() const;

	bool
	equal(
		pos_iterator const &
	) const;
private:
	pos current_;

	min min_;

	sup sup_;
};

}
}
}

#endif
