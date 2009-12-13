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


#ifndef FCPPT_LOG_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_HPP_INCLUDED

#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/tree_function.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/container/tree_decl.hpp>
#include <fcppt/variant/object_decl.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/export.hpp>

namespace fcppt
{
namespace log
{

class context {
	FCPPT_NONCOPYABLE(context)
public:
	FCPPT_SYMBOL context();

	FCPPT_SYMBOL ~context();

	FCPPT_SYMBOL void
	add(
		location const &,
		object &
	);

	FCPPT_SYMBOL void
	remove(
		location const &
	);

	FCPPT_SYMBOL object *
	find(
		location const &
	) const;

	FCPPT_SYMBOL void
	apply(
		location const &,
		tree_function const &
	);
private:
	detail::context_tree tree_;
};

}
}

#endif
