//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[sleep
#include <fcppt/time/sleep_any.hpp>
#include <fcppt/chrono/seconds.hpp>

int main()
{
	// sleep for 10 seconds
	fcppt::time::sleep_any(
		fcppt::chrono::seconds(
			10
		)
	);
}
//]
