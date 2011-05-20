//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[chronosystemclock
#include <fcppt/chrono/system_clock.hpp>
#include <fcppt/chrono/duration.hpp>
#include <fcppt/chrono/time_point.hpp>
#include <fcppt/time/ctime.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <ctime>

int main()
{
	typedef fcppt::chrono::system_clock clock;

	typedef clock::time_point time_point;

	// obtain the current time_point
	time_point const time1(
		clock::now()
	);

	// output the current time in its internal representation
	fcppt::io::cout
		<< FCPPT_TEXT("The time is ")
		<< time1
		<< FCPPT_TEXT('\n');

	// the time point can be converted to 'std::time_t'
	std::time_t const c_time(
		clock::to_time_t(
			time1
		)
	);

	// output the current time as string
	fcppt::io::cout
		<< fcppt::time::ctime(
			c_time
		)
		<< FCPPT_TEXT('\n');
}
//]
