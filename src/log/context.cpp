/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include "find_logger_node.hpp"
#include "find_location.hpp"
#include "find_inner_node.hpp"
#include "is_outer_node.hpp"
#include <fcppt/log/context.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/no_such_location.hpp>
#include <fcppt/container/tree_impl.hpp>
#include <fcppt/container/traversal.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert.hpp>
#include <exception>

fcppt::log::context::context()
:
	tree_(
		detail::inner_context_node(
			FCPPT_TEXT("")
		)
	)
{}

fcppt::log::context::~context()
{
	if(!std::uncaught_exception())
		FCPPT_ASSERT(
			tree_.empty()
		);
}

void
fcppt::log::context::add(
	location const &location_,
	object &object_
)
{
	detail::context_tree *cur(
		&tree_
	);

	for(
		location::const_iterator item(
			location_.begin()
		);
		item != location_.end();
		++item
	)
	{
		detail::context_tree::iterator const item_it(
			find_inner_node(
				*cur,
				*item
			)
		);

		if(
			item_it == cur->end()
		)
		{
			cur->push_back(
				detail::inner_context_node(
					*item
				)
			);

			cur = &cur->back();
		}
		else
			cur = &*item_it;
	}

	FCPPT_ASSERT(
		find_logger_node(
			*cur
		)
		== cur->end()
	);

	cur->push_back(
		detail::outer_context_node(
			object_
		)
	);
}

void
fcppt::log::context::remove(
	location const &location_
)
{
	detail::context_tree *node_(
		find_location(
			tree_,
			location_
		)
	);

	FCPPT_ASSERT(
		node_
	);

	detail::context_tree::iterator const logger_node_(
		find_logger_node(
			*node_
		)
	);

	FCPPT_ASSERT(
		logger_node_ != node_->end()
	);

	node_->erase(
		logger_node_->child_position()
	);

	while(
		node_->has_parent()
		&& node_->empty()
	)
	{
		detail::context_tree *const parent_(
			&node_->parent()
		);

		parent_->erase(
			node_->child_position()
		);

		node_ = parent_;
	}
}

fcppt::log::object *
fcppt::log::context::find(
	location const &location_
) const
{
	detail::context_tree const *const tree_location_(
		find_location(
			const_cast<
				detail::context_tree &
			>(
				tree_
			),
			location_
		)
	);

	if(!tree_location_)
		return 0;

	detail::context_tree::const_iterator const logger_node_(
		find_logger_node(
			const_cast<
				detail::context_tree &
			>(
				*tree_location_
			)
		)
	);

	return logger_node_ != tree_location_->end()
		?
			&logger_node_->value().get<
				detail::outer_context_node
			>().object()
		:
			0;
}

void
fcppt::log::context::apply(
	location const &location_,
	tree_function const &function_
)
{
	detail::context_tree *const tree_location_(
		find_location(
			tree_,
			location_
		)
	);

	if(
		!tree_location_
	)
		throw no_such_location(
			location_
		);

	typedef
	fcppt::container::traversal<
		detail::context_tree
	> traversal_type;

	traversal_type traversal_(
		*tree_location_
	);

	for(
		traversal_type::iterator it(
			traversal_.begin()
		);
		it != traversal_.end();
		++it
	)
	{
		if(
			is_outer_node(
				*it
			)
		)
			function_(
				it->value().get<
					detail::outer_context_node
				>().object()
			);
	}
}
