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


#include <fcppt/log/parameters/inherited.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/format/create_prefix.hpp>
#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/object.hpp>

fcppt::log::parameters::all const
fcppt::log::parameters::inherited(
	object &parent,
	string const &sub_location
)
{
	return
		all(
			parent.sink()
		)
		.parent(
			parent
		)
		.context_location(
			parent.context_location().context(),
			parent.context_location().location()
			+ sub_location
		)
		.enabled(
			parent.enabled()
		)
		.level_streams(
			parent.level_streams()
		)
		.enabled_levels(
			parent.enabled_levels()
		)
		.formatter(
			format::create_chain(
				parent.formatter(),
				format::create_prefix(
					sub_location
				)
			)
		);
}
