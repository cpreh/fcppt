//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/_.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/verbose.hpp>
#include <fcppt/log/parameters/object.hpp>


int
main()
{
//! [helloworld]
	// Create a logger that logs to cout, has level debug and "below"
	// enabled and is enabled itself.
	fcppt::log::object logger(
		fcppt::log::parameters::object()
		.level_defaults(
			fcppt::io::cout(),
			fcppt::log::level::debug
		)
		.enabled(
			true
		)
	);

	// Outputs: "debug: Hello World"
	if(
		logger.activated(
			fcppt::log::level::debug
		)
	)
		logger.log(
			fcppt::log::level::debug,
			fcppt::log::_
				<< FCPPT_TEXT("Hello World")
		);

	// The same as above using a shorthand macro
	FCPPT_LOG_DEBUG(
		logger,
		fcppt::log::_
			<< FCPPT_TEXT("Hello World")
	);

	// This is not printed because the verbose level is not enabled
	FCPPT_LOG_VERBOSE(
		logger,
		fcppt::log::_
			<< FCPPT_TEXT("Very verbose message")
	);
//! [helloworld]
}
