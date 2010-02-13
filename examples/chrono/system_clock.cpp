//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[chronosystemclock
#include <fcppt/chrono/system_clock.hpp>
#include <fcppt/chrono/duration.hpp>
#include <fcppt/chrono/time_point.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

int main()
{
	typedef fcppt::chrono::system_clock clock;

	typedef clock::time_point time_point;

	typedef clock::duration duration;

	time_point const time1(
		clock::now()
	);

	fcppt::io::cout
		<< FCPPT_TEXT("The time is ")
		<< time1
		<< FCPPT_TEXT('\n');
	
	time_point const time2(
		clock::now()
	);

	fcppt::io::cout
		<< FCPPT_TEXT("The first output took ")
		<< time2 - time1
		<< FCPPT_TEXT('\n');
}
//]
