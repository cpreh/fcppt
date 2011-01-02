//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/system_clock.hpp>

namespace
{

typedef fcppt::chrono::system_clock clock_type;

typedef clock_type::time_point some_time_point;

}

//[chrono_time_point_subtract
#include <fcppt/chrono/time_point.hpp>
#include <fcppt/chrono/duration.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

namespace
{

// some_time_point is just for exposition
typedef some_time_point time_point;

// call this to get a current time point
time_point const
obtain_time_point();

//<-
time_point const
obtain_time_point()
{
	return clock_type::now();
}
//->

void
f()
{
	typedef time_point::duration duration;

	time_point const t1(
		obtain_time_point()
	);

	time_point const t2(
		obtain_time_point()
	);

	duration const difference(
		t2 - t1
	);

	fcppt::io::cout
		<< difference
		<< FCPPT_TEXT('\n');
}

}
//]

//[chrono_time_point_convert
#include <fcppt/chrono/time_point_cast.hpp>
#include <fcppt/chrono/seconds.hpp>

namespace
{

void
g()
{
	// create a new time_point from our existing time_point type
	// that counts in seconds instead
	typedef fcppt::chrono::time_point<
		some_time_point::clock,
		fcppt::chrono::seconds
	> time_point_seconds;

	time_point const point1(
		obtain_time_point()
	);

	time_point_seconds const point2(
		fcppt::chrono::time_point_cast<
			time_point_seconds::duration // note: use the duration as destination type
		>(
			point1
		)
	);

	fcppt::io::cout
		<< point2
		<< FCPPT_TEXT('\n');
}

}
//]

//[chrono_time_point_epoch
namespace
{

void
h()
{
	time_point const point(
		obtain_time_point()
	);

	typedef time_point::duration duration;

	duration const absolute_duration(
		point.time_since_epoch()
	);

	fcppt::io::cout
		<< absolute_duration
		<< FCPPT_TEXT('\n');
}

}
//]

int main()
{
	f();

	g();

	h();
}
