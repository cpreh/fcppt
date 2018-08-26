//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_SPIRAL_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_SPIRAL_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/container/grid/spiral_iterator_fwd.hpp>
#include <fcppt/container/grid/detail/spiral_iterator_base.hpp>
#include <fcppt/iterator/base_decl.hpp>
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

template<
	typename Pos
>
class spiral_iterator final
:
	public
		fcppt::container::grid::detail::spiral_iterator_base<
			Pos
		>
{
	typedef
	fcppt::container::grid::detail::spiral_iterator_base<
		Pos
	>
	base_type;

	typedef
	Pos
	pos;
public:
	typedef
	fcppt::type_traits::value_type<
		base_type
	>
	value_type;

	static_assert(
		std::is_signed<
			fcppt::type_traits::value_type<
				Pos
			>
		>::value,
		"spiral_iterator only works with signed integers"
	);

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

	spiral_iterator(
		pos current,
		difference_type max_dist
	);

	void
	increment();

	reference
	dereference() const;

	bool
	equal(
		spiral_iterator const &
	) const;
private:
	pos cur_;

	difference_type max_dist_;

	difference_type cur_dist_;

	pos dir_;

	difference_type step_;

	static pos const start_dir;
};

}
}
}

#endif
