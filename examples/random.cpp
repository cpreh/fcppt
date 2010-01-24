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


#include <fcppt/random/uniform.hpp>
#include <fcppt/random/inclusive_range.hpp>
#include <fcppt/random/last_exclusive_range.hpp>
#include <fcppt/random/actor/normalized.hpp>
#include <fcppt/random/actor/element.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <iostream>
#include <ostream>
#include <exception>
#include <cstdlib>

namespace
{

template<
	typename Rng
>
void print_values(
	Rng &rng
)
{
	for(unsigned i = 0; i < 100; ++i)
		fcppt::io::cout << rng() << FCPPT_TEXT(' ');

	fcppt::io::cout << FCPPT_TEXT('\n');
}

void
test_function()
{
	fcppt::io::cout << FCPPT_TEXT("test\n");
}

}

int main()
try
{
	fcppt::random::uniform<int> rng(
		fcppt::random::make_inclusive_range(
			0,
			10
		)
	);

	print_values(rng);

	fcppt::random::uniform<float> rngf(
		fcppt::random::make_inclusive_range(
			0.f,
			10.f
		)
	);

	print_values(rngf);

	fcppt::random::uniform<int> rngex(
		fcppt::random::make_last_exclusive_range(
			0,
			10
		)
	);

	print_values(rngex);

	fcppt::random::actor::normalized actor(
		fcppt::assign::make_container<
			fcppt::random::actor::container
		>(
			fcppt::random::actor::element(
				10.,
				test_function
			)
		)
	);

	actor();
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
catch(
	std::exception const &e
)
{
	std::cerr
		<< e.what()
		<< '\n';
	
	return EXIT_FAILURE;
}
