//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/error.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/output.hpp>
#include <fcppt/log/parameters/object.hpp>


namespace
{

//! [logger_formatter_declaration]
fcppt::string const
logger_formatter(
	fcppt::string const &_text
)
{
	return
		FCPPT_TEXT("This is a formatting test: ")
		+
		_text;
}
//! [logger_formatter_declaration]

//! [error_formatter_declaration]

// Create a formatter for the error log level. Note that we have to append a
// newline here, because this is normally done by the default formatters for
// each log level.
fcppt::string const
error_formatter(
	fcppt::string const &_text
)
{
	return
		FCPPT_TEXT("Horrible error, please fix: ")
		+
		_text
		+
		FCPPT_TEXT('\n');
}
//! [error_formatter_declaration]

}

int
main()
{
//! [logger_declaration]
	fcppt::log::object logger(
		fcppt::log::parameters::object()
		.level_defaults(
			fcppt::io::cout(),
			fcppt::log::level::debug
		)
		.enabled(
			true
		)
		// Create a special formatter for the whole logger
		.formatter(
			logger_formatter
		)
		// Create a special sink for the error log level that prints to
		// cerr and also has a special formatter.
		.level_stream(
			fcppt::log::level::error,
			fcppt::log::level_stream(
				fcppt::io::cerr(),
				error_formatter
			)
		)
	);
//! [logger_declaration]

//! [log_print]
	// Prints:
	// 'This is a formatting test: debug: test'
	// to cout.
	FCPPT_LOG_DEBUG(
		logger,
		fcppt::log::_
			<< FCPPT_TEXT("test")
	);

	// Prints:
	// 'This is a formatting test: Horrible error, please fix: some error'
	// to cerr.
	FCPPT_LOG_ERROR(
		logger,
		fcppt::log::_
			<< FCPPT_TEXT("some error")
	);
//! [log_print]
}
