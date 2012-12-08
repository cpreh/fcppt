//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_DETAIL_ASSIGN_PARENTS_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DETAIL_ASSIGN_PARENTS_HPP_INCLUDED

#include <fcppt/container/tree/object_fwd.hpp>

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
void
assign_parents(
	fcppt::container::tree::object<
		T
	> &_object,
	typename fcppt::container::tree::object<
		T
	>::child_list &_children
)
{
	typedef typename fcppt::container::tree::object<
		T
	>::child_list child_list;

	for(
		auto &child : _children
	)
		child.parent(
			_object
		);
}

}
}
}
}

#endif
