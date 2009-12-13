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


#ifndef SGE_LOG_PARAMETERS_ALL_HPP_INCLUDED
#define SGE_LOG_PARAMETERS_ALL_HPP_INCLUDED

#include <sge/log/parameters/all_fwd.hpp>
#include <sge/log/object_fwd.hpp>
#include <sge/log/context_fwd.hpp>
#include <sge/log/level_stream_array.hpp>
#include <sge/log/enabled_level_array.hpp>
#include <sge/log/context_location.hpp>
#include <sge/log/location_fwd.hpp>
#include <sge/log/format/object_ptr.hpp>
#include <sge/ostream.hpp>
#include <sge/export.hpp>

namespace sge
{
namespace log
{
namespace parameters
{

class all {
public:
	SGE_SYMBOL explicit all(
		ostream &
	);

	SGE_SYMBOL all
	parent(
		object const &
	);

	SGE_SYMBOL all
	context_location(
		log::context *,
		log::location const &
	);

	SGE_SYMBOL all
	enabled(
		bool
	);

	SGE_SYMBOL all
	level_streams(
		level_stream_array const &
	);

	SGE_SYMBOL all
	enabled_levels(
		enabled_level_array const &
	);

	SGE_SYMBOL all
	formatter(
		format::const_object_ptr
	);

	SGE_SYMBOL ostream &
	sink() const;

	SGE_SYMBOL object const *
	parent() const;

	SGE_SYMBOL log::context_location const &
	context_location() const;

	SGE_SYMBOL bool
	enabled() const;

	SGE_SYMBOL level_stream_array const &
	level_streams() const;

	SGE_SYMBOL enabled_level_array const &
	enabled_levels() const;

	SGE_SYMBOL format::const_object_ptr const
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
