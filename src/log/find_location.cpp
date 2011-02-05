//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "find_location.hpp"
#include "find_inner_node.hpp"
#include <fcppt/log/location.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/variant/object_impl.hpp>

fcppt::log::detail::context_tree *
fcppt::log::find_location(
	detail::context_tree &_tree,
	log::location const &_location
)
{
	detail::context_tree *cur(
		&_tree
	);

	for(
		location::const_iterator item(
			_location.begin()
		);
		item != _location.end();
		++item
	)
	{
		detail::context_tree::iterator const item_it(
			log::find_inner_node(
				*cur,
				*item
			)
		);

		if(
			item_it == cur->end()
		)
			return 0;

		cur = &*item_it;
	}

	return cur;
}
