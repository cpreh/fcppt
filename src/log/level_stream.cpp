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


#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/temporary_output.hpp>
#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/format/object.hpp>

fcppt::log::level_stream::level_stream(
	ostream &dest_,
	format::const_object_ptr const formatter_
)
:
	dest_(dest_),
	formatter_(formatter_)
{}

fcppt::log::level_stream::~level_stream()
{}

void
fcppt::log::level_stream::log(
	temporary_output const &output,
	format::const_object_ptr const additional_formatter
)
{
	dest_
		<< format::create_chain(
			additional_formatter,
			formatter()
		)->format(
			output.result()
		);

	dest_.flush();
}

void
fcppt::log::level_stream::formatter(
	format::const_object_ptr const new_formatter
)
{
	formatter_ = new_formatter;
}

fcppt::log::format::const_object_ptr const
fcppt::log::level_stream::formatter() const
{
	return formatter_;
}
