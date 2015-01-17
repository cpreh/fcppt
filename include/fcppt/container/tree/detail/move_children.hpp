//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_DETAIL_MOVE_CHILDREN_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DETAIL_MOVE_CHILDREN_HPP_INCLUDED

#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{
namespace detail
{

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::child_list
move_children(
	fcppt::container::tree::object<
		T
	> &_parent,
	typename
	fcppt::container::tree::object<
		T
	>::child_list &&_children
)
{
	typedef fcppt::container::tree::object<
		T
	> object;

	typename object::child_list result(
		std::move(
			_children
		)
	);

	for(
		auto &child
		:
		result
	)
		child.parent(
			typename object::optional_ref(
				_parent
			)
		);

	return
		std::move(
			result
		);
}

}
}
}
}

#endif
