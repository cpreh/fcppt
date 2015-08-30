//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_CHILD_POSITION_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_CHILD_POSITION_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/algorithm/find_if_opt.hpp>
#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/container/tree/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

/**
\brief Returns an iterator pointing to the position in the parent's child
container where this object resides.

\ingroup fcpptcontaintertree

\param _parent The parent tree to search

\param _child The child to search for
*/
template<
	typename T
>
fcppt::optional<
	fcppt::container::to_iterator_type<
		T
	>
>
child_position(
	T &_parent,
	T &_child
)
{
	static_assert(
		fcppt::container::tree::is_object<
			typename
			std::remove_const<
				T
			>::type
		>::value,
		"T must be a tree"
	);

	return
		fcppt::algorithm::find_if_opt(
			_parent,
			[
				&_child
			](
				T &_tree
			)
			{
				return
					&_child
					==
					&_tree;
			}
		);
}

}
}
}

#endif
