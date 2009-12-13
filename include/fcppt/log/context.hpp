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


#ifndef SGE_LOG_CONTEXT_HPP_INCLUDED
#define SGE_LOG_CONTEXT_HPP_INCLUDED

#include <sge/log/context_fwd.hpp>
#include <sge/log/object_fwd.hpp>
#include <sge/log/location_fwd.hpp>
#include <sge/log/tree_function.hpp>
#include <sge/log/detail/context_tree.hpp>
#include <sge/container/tree_decl.hpp>
#include <sge/variant/object_decl.hpp>
#include <sge/noncopyable.hpp>
#include <sge/export.hpp>

namespace sge
{
namespace log
{

class context {
	SGE_NONCOPYABLE(context)
public:
	SGE_SYMBOL context();

	SGE_SYMBOL ~context();

	SGE_SYMBOL void
	add(
		location const &,
		object &
	);

	SGE_SYMBOL void
	remove(
		location const &
	);

	SGE_SYMBOL object *
	find(
		location const &
	) const;

	SGE_SYMBOL void
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
