//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[chronomonotonicclock
#include <fcppt/chrono/monotonic_clock.hpp>
#include <fcppt/chrono/time_point.hpp>
#include <fcppt/chrono/duration.hpp>
#include <fcppt/chrono/duration_cast.hpp>
#include <fcppt/chrono/milliseconds.hpp>
#include <fcppt/chrono/seconds.hpp>
#include <fcppt/time/sleep_any.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

int main()
{
	typedef fcppt::chrono::monotonic_clock clock;

	typedef clock::time_point time_point;

	typedef clock::duration duration;

	// obtain the first time point
	time_point const time1(
		clock::now()
	);

	// try to sleep for one second
	fcppt::time::sleep_any(
		fcppt::chrono::seconds(
			1
		)
	);

	// obtain the second time point
	time_point const time2(
		clock::now()
	);

	// calculate the elapsed time
	duration const diff(
		time2 - time1
	);

	// convert the elapsed time into milliseconds
	fcppt::chrono::milliseconds const millis(
		fcppt::chrono::duration_cast<
			fcppt::chrono::milliseconds
		>(
			diff
		)
	);

	// output the elapsed time in milliseconds
	fcppt::io::cout
		<< FCPPT_TEXT("Elapsed time in milliseconds: ")
		<< millis.count()
		<< FCPPT_TEXT('\n');
}
//]
