//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[loghelloworld
#include <fcppt/log/debug.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/output.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

int
main()
{
	// Create a logger that logs to cout,
	// has level debug and "below" enabled
	// and is enabled itself.
	fcppt::log::object logger(
		fcppt::log::parameters::all(
			fcppt::io::cout()
		)
		.level_defaults(
			fcppt::log::level::debug
		)
		.enabled(
			true
		)
	);

	// Outputs: mylogger: Hello World
	FCPPT_LOG_DEBUG(
		logger,
		fcppt::log::_
			<< FCPPT_TEXT("Hello World")
	);
}
//]
