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


#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/make_shared_ptr.hpp>

fcppt::log::format::const_object_ptr const
fcppt::log::format::create_chain(
	const_object_ptr const parent,
	const_object_ptr const child
)
{
	if(!parent)
		return child;

	if(!child)
		return parent;

	return
		make_shared_ptr<
			chain
		>(
			parent,
			child
		);
}
