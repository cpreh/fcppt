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


#include <fcppt/log/parameters/root.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/format/create_prefix.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/enabled_levels.hpp>

fcppt::log::parameters::root::root(
	io::ostream &sink_
)
:
	sink_(sink_),
	prefix_(),
	enabled_(false),
	level_(log::level::warning),
	context_(0)
{}

fcppt::log::parameters::root
fcppt::log::parameters::root::prefix(
	string const &nprefix_
)
{
	prefix_ = nprefix_;

	return *this;
}

fcppt::log::parameters::root
fcppt::log::parameters::root::enabled(
	bool const nenabled_
)
{
	enabled_ = nenabled_;

	return *this;
}

fcppt::log::parameters::root
fcppt::log::parameters::root::level(
	log::level::type const nlevel_
)
{
	level_ = nlevel_;

	return *this;
}

fcppt::log::parameters::root
fcppt::log::parameters::root::context(
	log::context &ncontext_
)
{
	context_ = &ncontext_;

	return *this;
}

fcppt::log::parameters::all const
fcppt::log::parameters::root::create() const
{
	return
		all(
			sink_
		)
		.context_location(
			context_,
			location(
				prefix_
			)
		)
		.enabled(
			enabled_
		)
		.level_streams(
			default_level_streams(
				sink_
			)
		)
		.enabled_levels(
			log::enabled_levels(
				level_
			)
		)
		.formatter(
			prefix_.empty()
			?
				format::const_object_ptr()
			:
				format::create_prefix(
					prefix_
				)
		);
}
