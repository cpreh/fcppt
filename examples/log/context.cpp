//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/info.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/out.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int
main()
try
{
// ![declare_context]
	fcppt::log::context context{
		fcppt::log::optional_level{
			fcppt::log::level::debug
		},
		fcppt::log::default_level_streams()
	};
// ![declare_context]

// ![declare_root_logger]
	fcppt::log::name const root_name{
		FCPPT_TEXT("root")
	};

	fcppt::log::object root_log{
		context,
		fcppt::log::parameters(
			root_name,
			fcppt::log::format::optional_function{}
		)
	};
// ![declare_root_logger]

// ![declare_child_logger]
	fcppt::log::name const child_name{
		FCPPT_TEXT("child")
	};

	fcppt::log::object child_log{
		root_log,
		fcppt::log::parameters(
			child_name,
			fcppt::log::format::optional_function{}
		)
	};
// ![declare_child_logger]

// ![log_debug]
	FCPPT_LOG_INFO(
		root_log,
		fcppt::log::out
			<< FCPPT_TEXT("Print from root!")
	)

	FCPPT_LOG_INFO(
		child_log,
		fcppt::log::out
			<< FCPPT_TEXT("Print from child!")
	)
// ![log_debug]

// ![context_set]
	context.set(
		fcppt::log::location{
			root_name
		}
		/
		child_name,
		fcppt::log::optional_level{
			fcppt::log::level::warning
		}
	);
// ![context_set]

// ![log_info]
	FCPPT_LOG_INFO(
		child_log,
		fcppt::log::out
			<< FCPPT_TEXT("shouldn't be shown!")
	)
// ![log_info]

// ![context_set2]
	context.set(
		fcppt::log::location{
			root_name
		},
		fcppt::log::optional_level{
			fcppt::log::level::debug
		}
	);

	FCPPT_LOG_INFO(
		child_log,
		fcppt::log::out
			<< FCPPT_TEXT("This is now shown!")
	)
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
