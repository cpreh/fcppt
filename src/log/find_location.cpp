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


#include "find_location.hpp"
#include "find_inner_node.hpp"
#include <fcppt/log/location.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/variant/object_impl.hpp>

fcppt::log::detail::context_tree *
fcppt::log::find_location(
	detail::context_tree &tree_,
	location const &location_
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
			return 0;

		cur = &*item_it;
	}

	return cur;
}
