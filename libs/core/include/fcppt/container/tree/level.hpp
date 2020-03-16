//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_LEVEL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_LEVEL_HPP_INCLUDED

#include <fcppt/container/size.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/to_root.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

/**
\brief Calculates the level of a tree

Calculates the \em level of \a _tree. A node without a parent has level 0. A
node with a parent has the level of its parent plus one.

\ingroup fcpptcontainertree
*/
template<
	typename Value
>
typename
fcppt::container::tree::object<
	Value
>::size_type
level(
	fcppt::container::tree::object<
		Value
	> const &_tree
)
{
	return
		fcppt::container::size(
			fcppt::container::tree::to_root<
				fcppt::container::tree::object<
					Value
				> const
			>(
				_tree
			)
		)
		-
		1U;
}

}
}
}

#endif
