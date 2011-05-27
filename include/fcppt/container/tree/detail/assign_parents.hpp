//          Copyright Carl Philipp Reh 2009 - 2011.
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
	tree::object<
		T
	> &_object,
	typename tree::object<
		T
	>::child_list &_children
)
{
	typedef typename tree::object<
		T
	>::child_list child_list;

	for(
		typename child_list::iterator it(
			_children.begin()
		);
		it != _children.end();
		++it
	)
		it->parent(
			_object
		);
}

}
}
}
}

#endif
