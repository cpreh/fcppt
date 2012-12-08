//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/no_such_location.hpp>
#include <fcppt/log/optional_object.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/detail/outer_context_node.hpp>
#include <fcppt/src/log/find_inner_node.hpp>
#include <fcppt/src/log/find_location.hpp>
#include <fcppt/src/log/find_logger_node.hpp>
#include <fcppt/src/log/is_outer_node.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>


fcppt::log::context::context()
:
	tree_(
		fcppt::log::detail::context_tree_node(
			fcppt::log::detail::inner_context_node(
				FCPPT_TEXT("")
			)
		)
	)
{
}

fcppt::log::context::~context()
{
	if(
		!std::uncaught_exception()
	)
		FCPPT_ASSERT_PRE(
			tree_.empty()
		);
}

fcppt::log::optional_object const
fcppt::log::context::find(
	fcppt::log::location const &_location
) const
{
	fcppt::log::detail::context_tree const *const tree_location(
		fcppt::log::find_location(
			const_cast<
				fcppt::log::detail::context_tree &
			>(
				tree_
			),
			_location
		)
	);

	if(
		!tree_location
	)
		return fcppt::log::optional_object();

	fcppt::log::detail::context_tree::const_iterator const logger_node(
		fcppt::log::find_logger_node(
			const_cast<
				fcppt::log::detail::context_tree &
			>(
				*tree_location
			)
		)
	);

	return
		logger_node != tree_location->end()
		?
			fcppt::log::optional_object(
				logger_node->value().get().get<
					fcppt::log::detail::outer_context_node
				>().object()
			)
		:
			fcppt::log::optional_object()
		;
}

void
fcppt::log::context::apply(
	log::location const &_location,
	log::tree_function const &_function
)
{
	fcppt::log::detail::context_tree *const tree_location(
		fcppt::log::find_location(
			tree_,
			_location
		)
	);

	if(
		!tree_location
	)
		throw fcppt::log::no_such_location(
			_location
		);

	typedef
	fcppt::container::tree::pre_order<
		fcppt::log::detail::context_tree
	> traversal_type;

	traversal_type traversal(
		*tree_location
	);

	for(
		fcppt::log::detail::context_tree const &elem : traversal
	)
	{
		if(
			fcppt::log::is_outer_node(
				elem
			)
		)
			_function(
				elem.value().get().get<
					fcppt::log::detail::outer_context_node
				>().object()
			);
	}
}

fcppt::log::detail::context_tree &
fcppt::log::context::add(
	fcppt::log::location const &_location,
	fcppt::log::object &_object
)
{
	fcppt::log::detail::context_tree *cur(
		&tree_
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
		{
			cur->push_back(
				fcppt::log::detail::context_tree_node(
					fcppt::log::detail::inner_context_node(
						item
					)
				)
			);

			cur = &cur->back();
		}
		else
			cur = &*item_it;
	}

	FCPPT_ASSERT_PRE(
		fcppt::log::find_logger_node(
			*cur
		)
		== cur->end()
	);

	cur->push_back(
		fcppt::log::detail::context_tree_node(
			fcppt::log::detail::outer_context_node(
				_object
			)
		)
	);

	return
		cur->back();
}

void
fcppt::log::context::remove(
	fcppt::log::detail::context_tree &_tree
)
{
	FCPPT_ASSERT_PRE(
		_tree.has_parent()
	);

	fcppt::log::detail::context_tree *node(
		&_tree.parent()
	);

	node->erase(
		_tree.child_position()
	);

	while(
		node->has_parent()
		&& node->empty()
	)
	{
		fcppt::log::detail::context_tree *const parent(
			&node->parent()
		);

		parent->erase(
			node->child_position()
		);

		node = parent;
	}
}
