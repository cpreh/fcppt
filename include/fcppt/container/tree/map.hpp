//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_MAP_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_MAP_HPP_INCLUDED

#include <fcppt/container/tree/is_object.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


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
typename
boost::enable_if<
	fcppt::container::tree::is_object<
		Result
	>,
	Result
>::type
map(
	fcppt::container::tree::object<
		Value
	> const &_tree,
	Function const _function
)
{
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
		std::move(
			result
		);
}

}
}
}

#endif
