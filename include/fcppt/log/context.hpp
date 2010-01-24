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
#include <fcppt/container/tree/object_decl.hpp>
#include <fcppt/variant/object_decl.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{

/// The logger context class is used for finding loggers at runtime.
class context
{
	FCPPT_NONCOPYABLE(context)
public:
	FCPPT_SYMBOL context();

	FCPPT_SYMBOL ~context();

	/// Adds a logger to a location
	/** The logger will call this indirectly if you provide a context in its parameters class.
	*/
	FCPPT_SYMBOL void
	add(
		location const &,
		object &
	);

	/// Removes the logger that is associated with a location.
	/* Loggers with a location set will indirectly call this on destruction.
	*/
	FCPPT_SYMBOL void
	remove(
		location const &
	);

	/// Finds a logger with a given location.
	/** @return 0 if the logger was not found
	*/
	FCPPT_SYMBOL object *
	find(
		location const &
	) const;

	/// apply a function to a location recursively
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
