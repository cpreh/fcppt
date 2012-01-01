//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[sleep
#include <fcppt/chrono/seconds.hpp>
#include <fcppt/time/sleep_any.hpp>


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
