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


#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/format/default_level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/foreach_enumerator.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <tr1/functional>

fcppt::log::level_stream_array const
fcppt::log::default_level_streams(
	ostream &sink_
)
{
	level_stream_array ret;

	FCPPT_FOREACH_ENUMERATOR(
		i,
		level
	)
	{
		ret[i] =
			make_shared_ptr<
				level_stream
			>(
				std::tr1::ref(
					sink_
				),
				format::default_level(
					i
				)
			);
	}

	return ret;
}
