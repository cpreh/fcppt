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


#include <fcppt/log/parameters/all.hpp>

fcppt::log::parameters::all::all(
	io::ostream &sink_
)
:
	sink_(&sink_),
	parent_(0),
	enabled_(false),
	level_streams_(),
	enabled_levels_(),
	formatter_(),
	context_location_()
{}

fcppt::log::parameters::all
fcppt::log::parameters::all::parent(
	object const &nparent_
)
{
	parent_ = &nparent_;

	return *this;
}

fcppt::log::parameters::all
fcppt::log::parameters::all::context_location(
	log::context *const ncontext_,
	log::location const &nlocation_
)
{
	context_location_
		= log::context_location(
			ncontext_,
			nlocation_
		);

	return *this;
}

fcppt::log::parameters::all
fcppt::log::parameters::all::enabled(
	bool nenabled_
)
{
	enabled_ = nenabled_;

	return *this;
}

fcppt::log::parameters::all
fcppt::log::parameters::all::level_streams(
	level_stream_array const &nlevel_streams_
)
{
	level_streams_ = nlevel_streams_;

	return *this;
}

fcppt::log::parameters::all
fcppt::log::parameters::all::enabled_levels(
	enabled_level_array const &nenabled_levels_
)
{
	enabled_levels_ = nenabled_levels_;

	return *this;
}

fcppt::log::parameters::all
fcppt::log::parameters::all::formatter(
	format::const_object_ptr const nformatter_
)
{
	formatter_ = nformatter_;

	return *this;
}

fcppt::io::ostream &
fcppt::log::parameters::all::sink() const
{
	return *sink_;
}

fcppt::log::object const *
fcppt::log::parameters::all::parent() const
{
	return parent_;
}

fcppt::log::context_location const &
fcppt::log::parameters::all::context_location() const
{
	return context_location_;
}

bool
fcppt::log::parameters::all::enabled() const
{
	return enabled_;
}

fcppt::log::level_stream_array const &
fcppt::log::parameters::all::level_streams() const
{
	return level_streams_;
}

fcppt::log::enabled_level_array const &
fcppt::log::parameters::all::enabled_levels() const
{
	return enabled_levels_;
}

fcppt::log::format::const_object_ptr const
fcppt::log::parameters::all::formatter() const
{
	return formatter_;
}
