//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/out.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/verbose.hpp>
#include <fcppt/log/format/optional_function.hpp>


int
main()
{
//! [helloworld]
	// Create a log context that has debug and every level above enabled
	fcppt::log::context context{
		fcppt::log::optional_level{
			fcppt::log::level::debug
		},
		fcppt::log::default_level_streams()
	};

	// Create a log object at location "{ fcppt }"
	fcppt::log::object log{
		context,
		fcppt::log::parameters{
			fcppt::log::name{
				FCPPT_TEXT("fcppt")
			},
			fcppt::log::format::optional_function{}
		}
	};

	// Outputs "fcppt: debug: Hello World"
	if(
		log.enabled(
			fcppt::log::level::debug
		)
	)
	{
		log.log(
			fcppt::log::level::debug,
			fcppt::log::out
				<< FCPPT_TEXT("Hello World")
		);
	}

	// The same as above using a shorthand macro
	FCPPT_LOG_DEBUG(
		log,
		fcppt::log::out
			<< FCPPT_TEXT("Hello World")
	)

	// This is not printed because the verbose level is not enabled
	FCPPT_LOG_VERBOSE(
		log,
		fcppt::log::out
			<< FCPPT_TEXT("Very verbose message")
	)
//! [helloworld]
}
