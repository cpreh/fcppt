//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "find_logger_node.hpp"
#include "find_location.hpp"
#include "find_inner_node.hpp"
#include "is_outer_node.hpp"
#include <fcppt/text.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/no_such_location.hpp>
#include <fcppt/log/optional_object.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/detail/outer_context_node.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>


fcppt::log::context::context()
:
	tree_(
		detail::context_tree_node(
			detail::inner_context_node(
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

void
fcppt::log::context::add(
	log::location const &_location,
	log::object &_object
)
{
	detail::context_tree *cur(
		&tree_
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
		{
			cur->push_back(
				detail::context_tree_node(
					detail::inner_context_node(
						*item
					)
				)
			);

			cur = &cur->back();
		}
		else
			cur = &*item_it;
	}

	FCPPT_ASSERT_PRE(
		log::find_logger_node(
			*cur
		)
		== cur->end()
	);

	cur->push_back(
		detail::context_tree_node(
			detail::outer_context_node(
				_object
			)
		)
	);
}

void
fcppt::log::context::remove(
	log::location const &_location
)
{
	detail::context_tree *node(
		log::find_location(
			tree_,
			_location
		)
	);

	FCPPT_ASSERT_PRE(
		node != 0
	);

	detail::context_tree::iterator const logger_node(
		log::find_logger_node(
			*node
		)
	);

	FCPPT_ASSERT_PRE(
		logger_node != node->end()
	);

	node->erase(
		logger_node->child_position()
	);

	while(
		node->has_parent()
		&& node->empty()
	)
	{
		detail::context_tree *const parent(
			&node->parent()
		);

		parent->erase(
			node->child_position()
		);

		node = parent;
	}
}

fcppt::log::detail::context_tree const *
fcppt::log::context::find_node(
	log::location const &_location
) const
{
	detail::context_tree const *const tree_location(
		log::find_location(
			const_cast<
				detail::context_tree &
			>(
				tree_
			),
			_location
		)
	);

	if(
		!tree_location
	)
		return 0;

	detail::context_tree::const_iterator const logger_node(
		log::find_logger_node(
			const_cast<
				detail::context_tree &
			>(
				*tree_location
			)
		)
	);

	return
		logger_node != tree_location->end()
		?
			&*logger_node
		:
			0
		;
}


fcppt::log::optional_object const
fcppt::log::context::find(
	log::location const &_location
) const
{
	detail::context_tree const *const node(
		this->find_node(
			_location
		)
	);

	return
		node
		?
			log::optional_object(
				node->value().get<
					detail::outer_context_node
				>().object()
			)
		:
			log::optional_object()
		;
}

void
fcppt::log::context::apply(
	log::location const &_location,
	log::tree_function const &_function
)
{
	detail::context_tree *const tree_location(
		log::find_location(
			tree_,
			_location
		)
	);

	if(
		!tree_location
	)
		throw log::no_such_location(
			_location
		);

	typedef
	fcppt::container::tree::pre_order<
		detail::context_tree
	> traversal_type;

	traversal_type traversal(
		*tree_location
	);

	for(
		traversal_type::iterator it(
			traversal.begin()
		);
		it != traversal.end();
		++it
	)
	{
		if(
			log::is_outer_node(
				*it
			)
		)
			_function(
				it->value().get<
					detail::outer_context_node
				>().object()
			);
	}
}
