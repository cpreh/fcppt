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


#ifndef SGE_LOG_OBJECT_HPP_INCLUDED
#define SGE_LOG_OBJECT_HPP_INCLUDED

#include <sge/log/object_fwd.hpp>
#include <sge/log/detail/auto_context.hpp>
#include <sge/log/parameters/all_fwd.hpp>
#include <sge/log/level_stream_array.hpp>
#include <sge/log/enabled_level_array.hpp>
#include <sge/log/temporary_output_fwd.hpp>
#include <sge/log/level.hpp>
#include <sge/log/level_stream_fwd.hpp>
#include <sge/log/context_location_fwd.hpp>
#include <sge/log/format/object_ptr.hpp>
#include <sge/ostream.hpp>
#include <sge/export.hpp>
#include <sge/noncopyable.hpp>

namespace sge
{
namespace log
{

class object {
	SGE_NONCOPYABLE(object)
public:
	SGE_SYMBOL explicit object(
		parameters::all const &
	);

	SGE_SYMBOL ~object();

	SGE_SYMBOL void
	log(
		level::type,
		temporary_output const &
	);

	SGE_SYMBOL level_stream &
	level_sink(
		level::type
	);

	SGE_SYMBOL level_stream const &
	level_sink(
		level::type
	) const;

	SGE_SYMBOL void
	activate(
		level::type
	);

	SGE_SYMBOL void
	deactivate(
		level::type
	);

	SGE_SYMBOL bool
	activated(
		level::type
	) const;

	SGE_SYMBOL void
	enable(
		bool
	);

	SGE_SYMBOL bool
	enabled() const;

	SGE_SYMBOL ostream &
	sink() const;

	SGE_SYMBOL format::const_object_ptr const
	formatter() const;

	SGE_SYMBOL
	log::context_location const
	context_location() const;

	SGE_SYMBOL
	level_stream_array const &
	level_streams() const;

	SGE_SYMBOL
	enabled_level_array const &
	enabled_levels() const;
private:
	object const *const parent_;

	ostream &sink_;

	detail::auto_context auto_context_;

	format::const_object_ptr const formatter_;

	bool enabled_;

	level_stream_array level_streams_;

	enabled_level_array enabled_levels_;
};

}
}

#endif
