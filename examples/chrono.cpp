//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/chrono.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


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
