//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/enum/array_init.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/error.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/out.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/format/default_level.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/optional_function.hpp>


namespace
{

//! [logger_formatter_declaration]
fcppt::string
log_formatter(
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
fcppt::string
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
//! [logger_streams]
	auto const level_streams(
		fcppt::enum_::array_init<
			fcppt::log::level_stream_array
		>(
			[](
				fcppt::log::level const _level
			)
			{
				// Create a special sink for the error log level that prints to
				// cerr and also has a special formatter.
				return
					_level
					==
					fcppt::log::level::error
					?
						fcppt::log::level_stream(
							fcppt::io::cerr(),
							fcppt::log::format::optional_function{
								fcppt::log::format::function{
									error_formatter
								}
							}
						)
					:
						fcppt::log::level_stream(
							fcppt::io::cout(),
							fcppt::log::format::optional_function(
								fcppt::log::format::default_level(
									_level
								)
							)
						)
					;
			}
		)
	);
//! [logger_streams]

//! [logger_context]
	fcppt::log::context context{
		fcppt::log::optional_level{
			fcppt::log::level::debug
		},
		fcppt::log::level_stream_array{
			level_streams
		}
	};
//! [logger_context]

//! [logger_declaration]
	fcppt::log::object log{
		context,
		fcppt::log::parameters{
			fcppt::log::name{
				FCPPT_TEXT("fcppt")
			},
			// Create a special formatter for the whole log
			fcppt::log::format::optional_function{
				fcppt::log::format::function{
					log_formatter
				}
			}
		}
	};
//! [logger_declaration]

//! [log_print]
	// Prints:
	// 'This is a formatting test: fcppt: debug: test'
	// to cout.
	FCPPT_LOG_DEBUG(
		log,
		fcppt::log::out
			<< FCPPT_TEXT("test")
	)

	// Prints:
	// 'This is a formatting test: fcppt: Horrible error, please fix: some error'
	// to cerr.
	FCPPT_LOG_ERROR(
		log,
		fcppt::log::out
			<< FCPPT_TEXT("some error")
	)
//! [log_print]
}
