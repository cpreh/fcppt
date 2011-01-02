//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[chrono_duration_decl
#include <fcppt/chrono/duration.hpp>
#include <fcppt/ratio/ratio.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

namespace
{

void
f()
{
	// typedef a duration that uses long as its internal type
	// and counts in milliseconds (1 / 1000 seconds)
	typedef fcppt::chrono::duration<
		long,
		fcppt::ratio::object<
			1,
			1000
		>
	> milliseconds;

	// represents 500 milliseconds
	milliseconds const test(
		500
	);

	fcppt::io::cout
		<< test
		<< FCPPT_TEXT('\n');
}

}
//]

//[chrono_duration_convert
#include <fcppt/chrono/hours.hpp>
#include <fcppt/chrono/milliseconds.hpp>
#include <fcppt/chrono/duration_cast.hpp>

namespace
{

void
g()
{
	fcppt::chrono::hours const hour(
		1
	);

	// convert an hour into milliseconds
	fcppt::chrono::milliseconds const millis(
		fcppt::chrono::duration_cast<
			fcppt::chrono::milliseconds
		>(
			hour
		)
	);

	// prints 3600000
	fcppt::io::cout
		<< millis
		<< FCPPT_TEXT('\n');
}

}
//]

//[chrono_duration_count
#include <fcppt/chrono/seconds.hpp>

namespace
{

void
h()
{
	fcppt::chrono::seconds const seconds(
		100
	);

	typedef fcppt::chrono::seconds::rep rep;

	// get the internal value
	rep const internal_value(
		seconds.count()
	);

	// prints 100
	fcppt::io::cout
		<< internal_value
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
