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


#include <fcppt/io/cout.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>

int main()
{
	typedef fcppt::optional<
		fcppt::string
	> optional_string;

	optional_string opt1(
		FCPPT_TEXT("test")
	);

	optional_string opt2(
		opt1
	);

	fcppt::io::cout
		<< *opt1
		<< FCPPT_TEXT('\n')
		<< *opt2
		<< FCPPT_TEXT('\n');

	opt2 = FCPPT_TEXT("test2");
	opt1 = opt2;

	fcppt::io::cout
		<< *opt1
		<< FCPPT_TEXT('\n')
		<< *opt2
		<< FCPPT_TEXT('\n');

	if(opt1)
		fcppt::io::cout << FCPPT_TEXT("opt1 is set\n");

	opt1.reset();

	if(!opt1)
		fcppt::io::cout << FCPPT_TEXT("opt1 is not set\n");
}
