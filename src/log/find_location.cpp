//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/location.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/optional_context_tree_ref.hpp>
#include <fcppt/src/log/find_inner_node.hpp>
#include <fcppt/src/log/find_location.hpp>


fcppt::log::detail::optional_context_tree_ref const
fcppt::log::find_location(
	fcppt::log::detail::context_tree &_tree,
	fcppt::log::location const &_location
)
{
	fcppt::log::detail::optional_context_tree_ref cur(
		_tree
	);

	for(
		auto const &item : _location
	)
	{
		fcppt::log::detail::context_tree::iterator const item_it(
			fcppt::log::find_inner_node(
				*cur,
				item
			)
		);

		if(
			item_it == cur->end()
		)
			return
				fcppt::log::detail::optional_context_tree_ref();

		cur =
			fcppt::log::detail::optional_context_tree_ref(
				*item_it
			);
	}

	return cur;
}
