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


#include <fcppt/container/field.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <exception>
#include <iostream>
#include <ostream>
#include <cstdlib>

int main()
try
{
	typedef fcppt::container::field<
		int
	> field_type;

	field_type f(
		field_type::dim_type(
			2,2
		)
	);

	f.pos(field_type::vector_type(0,0)) = 0;
	f.pos(field_type::vector_type(1,0)) = 1;
	f.pos(field_type::vector_type(0,1)) = 2;
	f.pos(field_type::vector_type(1,1)) = 3;
	
	fcppt::io::cout
		<< f
		<< SGE_TEXT('\n');

	f.resize_canvas(
		field_type::dim_type(
			1,
			1
		),
		9
	);
	
	fcppt::io::cout
		<< f
		<< SGE_TEXT('\n');
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< SGE_TEXT("caught fcppt exception: ")
		<< e.string()
		<< SGE_TEXT('\n');

	return EXIT_FAILURE;
}
catch(
	std::exception const &e
)
{
	std::cerr
		<< "caught std exception: "
		<< e.what()
		<< '\n';

	return EXIT_FAILURE;
}
catch(...)
{
	std::cerr << "caught unknown exception\n";

	return EXIT_FAILURE;
}
