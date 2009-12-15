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


#include <fcppt/chrono/chrono.hpp>
#include <iostream>
#include <ostream>
#include <cmath>

int main()
{
	fcppt::chrono::system_clock::time_point const tp(
		fcppt::chrono::system_clock::now()
	);

	typedef
	fcppt::chrono::time_point<
		fcppt::chrono::system_clock,
		fcppt::chrono::seconds
	> other_time;

	other_time const ot(
		fcppt::chrono::time_point_cast<
			other_time::duration
		>(
			tp
		)
	);

	std::cout << ot << '\n';

	std::cout
		<< fcppt::chrono::time_point_cast<
			fcppt::chrono::days
		>(
			ot
		)
		<< '\n';

	// measure some time:

	typedef fcppt::chrono::high_resolution_clock::time_point hrc_tp;

	hrc_tp const begin(
		fcppt::chrono::high_resolution_clock::now()
	);

	for(
		unsigned i = 0;
		i < 100;
		++i
	)
		std::cout
			<< std::sqrt(
				static_cast<
					float
				>(
					i
				)
			)
			<< ' ';

	hrc_tp const end(
		fcppt::chrono::high_resolution_clock::now()
	);

	hrc_tp::duration const time_taken(
		end - begin
	);

	std::cout
		<< "\ntime taken: "
		<< time_taken
		<< " (in units of "
		<< hrc_tp::period::num
		<< '/'
		<< hrc_tp::period::den
		<< "), in seconds: "
		<< fcppt::chrono::duration_cast<
			fcppt::chrono::duration<
				double
			>
		>(
			time_taken
		)
		<< '\n';
}
