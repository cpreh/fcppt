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


#include <fcppt/log/level_string.hpp>
#include <fcppt/tr1/array.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <algorithm>
#include <iterator>

namespace
{

typedef std::tr1::array<
	fcppt::string,
	fcppt::log::level::size
> name_array;

name_array const names = {
{
	FCPPT_TEXT("debug"),
	FCPPT_TEXT("info"),
	FCPPT_TEXT("warning"),
	FCPPT_TEXT("error"),
	FCPPT_TEXT("fatal")
} };

}

fcppt::log::level::type
fcppt::log::level_from_string(
	string const &str
)
{
	name_array::const_iterator const it(
		std::find(
			names.begin(),
			names.end(),
			str
		)
	);

	if(
		it == names.end()
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
					name_array const &
				>(
					names
				).begin(),
				it
			)
		);
}

fcppt::string const
fcppt::log::level_to_string(
	level::type const level_)
{
	return
		names.at(
			static_cast<
				name_array::size_type
			>(
				level_
			)
		);
}
