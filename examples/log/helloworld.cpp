//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/_.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/enabled_levels.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/setting.hpp>
#include <fcppt/log/verbose.hpp>
#include <fcppt/log/format/optional_function.hpp>


int
main()
{
//! [helloworld]
	// Create a logger context that has debug and every level above enabled
	fcppt::log::context context{
		fcppt::log::setting{
			fcppt::log::enabled_levels(
				fcppt::log::level::debug
			)
		}
	};

	// Create a logger that logs to cout
	fcppt::log::object logger{
		context,
		fcppt::log::parameters{
			fcppt::log::name{
				FCPPT_TEXT("fcppt")
			},
			fcppt::log::default_level_streams(
				fcppt::io::cout()
			),
			fcppt::log::format::optional_function{}
		}
	};

	// Outputs: "debug: Hello World"
	if(
		logger.enabled(
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
