//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_MAP_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_MAP_HPP_INCLUDED

#include <fcppt/container/tree/is_object.hpp>
#include <fcppt/container/tree/object_impl.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

/**
\brief Maps a tree to another tree

\ingroup fcpptcontainertree

Maps \a _tree to another tree using \a _function.
*/
template<
	typename Result,
	typename Value,
	typename Function
>
Result
map(
	fcppt::container::tree::object<
		Value
	> const &_tree,
	Function const _function
)
{
	static_assert(
		fcppt::container::tree::is_object<
			Result
		>::value,
		"The result of tree::map must be a tree"
	);

	Result result(
		_function(
			_tree.value()
		)
	);

	for(
		auto const &child
		:
		_tree
	)
		result.push_back(
			fcppt::container::tree::map<
				Result
			>(
				child,
				_function
			)
		);

	return
		result;
}

}
}
}

#endif
