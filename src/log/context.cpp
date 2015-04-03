//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/maybe.hpp>
#include <fcppt/optional_bind.hpp>
#include <fcppt/string.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/no_such_location.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_object.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/detail/outer_context_node.hpp>
#include <fcppt/src/log/find_inner_node.hpp>
#include <fcppt/src/log/find_location.hpp>
#include <fcppt/src/log/find_logger_node.hpp>
#include <fcppt/src/log/is_outer_node.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <vector>
#include <fcppt/config/external_end.hpp>


fcppt::log::context::context()
:
	tree_(
		fcppt::log::detail::context_tree_node(
			fcppt::log::detail::inner_context_node(
				fcppt::string()
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
	return
		fcppt::optional_bind(
			fcppt::log::find_location(
				const_cast<
					fcppt::log::detail::context_tree &
				>(
					tree_
				),
				_location
			),
			[](
				fcppt::log::detail::context_tree &_tree_location
			)
			{
				fcppt::log::detail::context_tree::const_iterator const logger_node(
					fcppt::log::find_logger_node(
						const_cast<
							fcppt::log::detail::context_tree &
						>(
							_tree_location
						)
					)
				);

				return
					logger_node != _tree_location.end()
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
		);
}

void
fcppt::log::context::apply(
	fcppt::log::location const &_location,
	fcppt::log::tree_function const &_function
)
{
	fcppt::maybe(
		fcppt::log::find_location(
			tree_,
			_location
		),
		[
			&_location
		]{
			throw fcppt::log::no_such_location(
				_location
			);
		},
		[
			this,
			&_function
		](
			fcppt::log::detail::context_tree &_tree_location
		)
		{
			this->apply_to(
				_function,
				_tree_location
			);
		}
	);
}

void
fcppt::log::context::apply_all(
	fcppt::log::tree_function const &_function
)
{
	this->apply_to(
		_function,
		tree_
	);
}

void
fcppt::log::context::transfer_to(
	fcppt::log::context &_other
)
{
	typedef
	std::vector<
		fcppt::log::detail::outer_context_node
	>
	outer_context_node_vector;

	outer_context_node_vector nodes;

	for(
		fcppt::log::detail::context_tree const &elem
		:
		fcppt::container::tree::pre_order<
			fcppt::log::detail::context_tree
		>(
			tree_
		)
	)
		if(
			fcppt::log::is_outer_node(
				elem
			)
		)
			nodes.push_back(
				elem.value().get().get<
					fcppt::log::detail::outer_context_node
				>()
			);

	for(
		auto const &node
		:
		nodes
	)
		node.object().transfer(
			_other
		);

	FCPPT_ASSERT_ERROR(
		tree_.empty()
	);
}

void
fcppt::log::context::apply_to(
	fcppt::log::tree_function const &_function,
	fcppt::log::detail::context_tree const &_tree
)
{
	for(
		fcppt::log::detail::context_tree const &elem
		:
		fcppt::container::tree::pre_order<
			fcppt::log::detail::context_tree const
		>(
			_tree
		)
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
		auto const &item
		:
		_location
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
	fcppt::log::detail::context_tree::optional_ref node(
		_tree.parent()
	);

	FCPPT_ASSERT_PRE(
		node
	);

	node.get_unsafe().erase(
		_tree.child_position()
	);

	while(
		node.get_unsafe().parent()
		&&
		node.get_unsafe().empty()
	)
	{
		fcppt::log::detail::context_tree::optional_ref const parent(
			node.get_unsafe().parent()
		);

		parent.get_unsafe().erase(
			node.get_unsafe().child_position()
		);

		node = parent;
	}
}
