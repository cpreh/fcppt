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


#ifndef FCPPT_LOG_OBJECT_HPP_INCLUDED
#define FCPPT_LOG_OBJECT_HPP_INCLUDED

#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/detail/auto_context.hpp>
#include <fcppt/log/parameters/all_fwd.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/temporary_output_fwd.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream_fwd.hpp>
#include <fcppt/log/context_location_fwd.hpp>
#include <fcppt/log/format/object_ptr.hpp>
#include <fcppt/ostream.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace fcppt
{
namespace log
{

class object {
	FCPPT_NONCOPYABLE(object)
public:
	FCPPT_SYMBOL explicit object(
		parameters::all const &
	);

	FCPPT_SYMBOL ~object();

	FCPPT_SYMBOL void
	log(
		level::type,
		temporary_output const &
	);

	FCPPT_SYMBOL level_stream &
	level_sink(
		level::type
	);

	FCPPT_SYMBOL level_stream const &
	level_sink(
		level::type
	) const;

	FCPPT_SYMBOL void
	activate(
		level::type
	);

	FCPPT_SYMBOL void
	deactivate(
		level::type
	);

	FCPPT_SYMBOL bool
	activated(
		level::type
	) const;

	FCPPT_SYMBOL void
	enable(
		bool
	);

	FCPPT_SYMBOL bool
	enabled() const;

	FCPPT_SYMBOL ostream &
	sink() const;

	FCPPT_SYMBOL format::const_object_ptr const
	formatter() const;

	FCPPT_SYMBOL
	log::context_location const
	context_location() const;

	FCPPT_SYMBOL
	level_stream_array const &
	level_streams() const;

	FCPPT_SYMBOL
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
