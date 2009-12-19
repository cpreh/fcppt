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


#include "level_strings.hpp"
#include <fcppt/log/level_from_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <algorithm>
#include <iterator>

fcppt::log::level::type
fcppt::log::level_from_string(
	string const &str
)
{
	level_string_array::const_iterator const it(
		std::find(
			level_strings.begin(),
			level_strings.end(),
			str
		)
	);

	if(
		it == level_strings.end()
	)
		throw exception(
			FCPPT_TEXT("level_from_string(): \"")
			+ str
			+ FCPPT_TEXT("\" not found!")
		);

	return
		static_cast<
			level::type
		>(
			std::distance(
				static_cast<
					level_string_array const &
				>(
					level_strings
				).begin(),
				it
			)
		);
}
