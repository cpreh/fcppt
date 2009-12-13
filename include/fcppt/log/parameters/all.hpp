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


#ifndef FCPPT_LOG_PARAMETERS_ALL_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_ALL_HPP_INCLUDED

#include <fcppt/log/parameters/all_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/format/object_ptr.hpp>
#include <fcppt/ostream.hpp>
#include <fcppt/export.hpp>

namespace fcppt
{
namespace log
{
namespace parameters
{

class all {
public:
	FCPPT_SYMBOL explicit all(
		ostream &
	);

	FCPPT_SYMBOL all
	parent(
		object const &
	);

	FCPPT_SYMBOL all
	context_location(
		log::context *,
		log::location const &
	);

	FCPPT_SYMBOL all
	enabled(
		bool
	);

	FCPPT_SYMBOL all
	level_streams(
		level_stream_array const &
	);

	FCPPT_SYMBOL all
	enabled_levels(
		enabled_level_array const &
	);

	FCPPT_SYMBOL all
	formatter(
		format::const_object_ptr
	);

	FCPPT_SYMBOL ostream &
	sink() const;

	FCPPT_SYMBOL object const *
	parent() const;

	FCPPT_SYMBOL log::context_location const &
	context_location() const;

	FCPPT_SYMBOL bool
	enabled() const;

	FCPPT_SYMBOL level_stream_array const &
	level_streams() const;

	FCPPT_SYMBOL enabled_level_array const &
	enabled_levels() const;

	FCPPT_SYMBOL format::const_object_ptr const
	formatter() const;
private:
	ostream *sink_;

	object const *parent_;

	bool enabled_;

	level_stream_array level_streams_;

	enabled_level_array enabled_levels_;

	format::const_object_ptr formatter_;

	log::context_location context_location_;
};

}
}
}

#endif
