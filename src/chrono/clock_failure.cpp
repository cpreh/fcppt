//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/clock_failure.hpp>

fcppt::chrono::clock_failure::clock_failure(
	fcppt::string const &e
)
:
	exception(
		e
	)
{}
