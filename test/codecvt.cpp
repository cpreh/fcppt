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


#include <fcppt/io/cerr.hpp>
#include <fcppt/codecvt.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <string>
#include <cstdlib>

int main()
try
{
	std::wstring const test(
		L"localhost"
	);

	std::string const narrow(
		fcppt::narrow(
			test
		)
	);

	std::wstring const back(
		fcppt::widen(
			narrow
		)
	);

	if(back != test)
		fcppt::io::cerr << FCPPT_TEXT("Strings are not equal!\n");
	else
		fcppt::io::cerr << FCPPT_TEXT("Strings are equal!\n");
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< e.string()
		<< FCPPT_TEXT('\n');
	
	return EXIT_FAILURE;
}
