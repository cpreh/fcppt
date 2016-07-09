//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/_.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/enabled_levels.hpp>
#include <fcppt/log/info.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/location_setting.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/setting.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int
main()
try
{
// ![declare_context]
	fcppt::log::context context{
		fcppt::log::setting(
			fcppt::log::enabled_levels(
				fcppt::log::level::debug
			)
		)
	};
// ![declare_context]

// ![declare_root_logger]
	fcppt::log::location const root_location{
		FCPPT_TEXT("root")
	};

	fcppt::log::object logger{
		fcppt::log::parameters(
			context,
			root_location,
			fcppt::log::default_level_streams(
				fcppt::io::cout()
			),
			fcppt::log::format::optional_function{}
		)
	};
// ![declare_root_logger]

// ![declare_child_logger]
	fcppt::log::location const child_location{
		root_location
		/
		FCPPT_TEXT("child")
	};

	fcppt::log::object child_logger{
		fcppt::log::parameters(
			context,
			child_location,
			fcppt::log::default_level_streams(
				fcppt::io::cout()
			),
			fcppt::log::format::optional_function{}
		)
	};
// ![declare_child_logger]

// ![log_debug]
	FCPPT_LOG_INFO(
		logger,
		fcppt::log::_
			<< FCPPT_TEXT("Print from root!")
	);

	FCPPT_LOG_INFO(
		child_logger,
		fcppt::log::_
			<< FCPPT_TEXT("Print from child!")
	);
// ![log_debug]

// ![context_set]
	context.set(
		fcppt::log::location_setting{
			child_location,
			fcppt::log::setting{
				fcppt::log::enabled_levels(
					fcppt::log::level::warning
				)
			}
		}
	);
// ![context_set]

// ![log_info]
	FCPPT_LOG_INFO(
		child_logger,
		fcppt::log::_
			<< FCPPT_TEXT("shouldn't be shown!")
	);
// ![log_info]

// ![context_set2]
	context.set(
		fcppt::log::location_setting{
			root_location,
			fcppt::log::setting{
				fcppt::log::enabled_levels(
					fcppt::log::level::debug
				)
			}
		}
	);

	FCPPT_LOG_INFO(
		child_logger,
		fcppt::log::_
			<< FCPPT_TEXT("This is now shown!")
	);
// ![context_set2]

	return
		EXIT_SUCCESS;
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');

	return
		EXIT_FAILURE;
}
