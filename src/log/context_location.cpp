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


#include <fcppt/log/context_location.hpp>
#include <fcppt/assert.hpp>

fcppt::log::context_location::context_location()
:
	context_(),
	location_()
{}

fcppt::log::context_location::context_location(
	log::context *const context_,
	log::location const &location_
)
:
	context_(context_),
	location_(location_)
{}

fcppt::log::context *
fcppt::log::context_location::context() const
{
	return context_;
}

fcppt::log::location const &
fcppt::log::context_location::location() const
{
	FCPPT_ASSERT(
		location_
	);

	return *location_;
}
