//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/src/log/find_inner_node.hpp>
#include <fcppt/src/log/find_location.hpp>
#include <fcppt/variant/object_impl.hpp>


fcppt::log::detail::context_tree *
fcppt::log::find_location(
	fcppt::log::detail::context_tree &_tree,
	fcppt::log::location const &_location
)
{
	fcppt::log::detail::context_tree *cur(
		&_tree
	);

	for(
		fcppt::log::location::const_iterator item(
			_location.begin()
		);
		item != _location.end();
		++item
	)
	{
		fcppt::log::detail::context_tree::iterator const item_it(
			fcppt::log::find_inner_node(
				*cur,
				*item
			)
		);

		if(
			item_it == cur->end()
		)
			return nullptr;

		cur = &*item_it;
	}

	return cur;
}
