//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[logcomplex
#include <fcppt/exception.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/define_context.hpp>
#include <fcppt/log/error.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/output.hpp>
#include <fcppt/log/parameters/object.hpp>
#include <fcppt/log/parameters/with_context.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


//! [context_declaration]
namespace engine
{

// Function to retrieve the global log context
fcppt::log::context &
log_context();

}
//! [context_declaration]

//! [logger_parameters]
namespace engine
{

// Helper function to create our logger parameters
inline
fcppt::log::parameters::object const
logger_parameters(
	fcppt::log::location const &_location
)
{
	return
		fcppt::log::parameters::with_context(
			engine::log_context(),
			_location
		)
		.level_defaults(
			fcppt::io::cout(),
			fcppt::log::level::debug
		);
}

}
//! [logger_parameters]

//! [engine_location]
namespace engine
{

// Helper function to return the engine's log location
inline
fcppt::log::location const
logger_location()
{
	return
		fcppt::log::location(
			FCPPT_TEXT("engine")
		);
}

}
//! [engine_location]

//! [declare_engine_root_logger]
namespace engine
{

// The engine's root logger
fcppt::log::object &
root_logger();

}
//! [declare_engine_root_logger]

//! [declare_subsystem_loggers]
// Define two subsystem loggers.
namespace engine
{
namespace renderer
{

fcppt::log::object &
logger();

}

namespace audio
{

fcppt::log::object &
logger();

}
}
//! [declare_subsystem_loggers]

//! [context_definition]
//
// Translation unit for the global log context
//

FCPPT_LOG_DEFINE_CONTEXT(
	engine::log_context
)
//! [context_definition]

//! [define_engine_root_logger]
//
// Translation unit for the root logger
//

namespace
{

fcppt::log::object root_logger_obj(
	engine::logger_parameters(
		engine::logger_location()
	)
);

}

fcppt::log::object &
engine::root_logger()
{
	return root_logger_obj;
}
//! [define_engine_root_logger]

//! [define_subsystem_loggers]
//
// Translation unit for the renderer logger
//
namespace
{

fcppt::log::object renderer_logger_obj(
	engine::logger_parameters(
		engine::logger_location()
		/
		FCPPT_TEXT("renderer")
	)
);

}

fcppt::log::object &
engine::renderer::logger()
{
	return renderer_logger_obj;
}

//
// Translation unit for the audio logger
//

namespace
{

fcppt::log::object audio_logger_obj(
	engine::logger_parameters(
		engine::logger_location()
		/
		FCPPT_TEXT("audio")
	)
);

}

fcppt::log::object &
engine::audio::logger()
{
	return audio_logger_obj;
}
//! [define_subsystem_loggers]

int
main(
	int argc,
	char **argv
)
try
{
//! [main]
	// Each command line parameter specifies a logger to activate.
	// Example: "./example renderer" will activate the renderer's logger so we can
	// diagnose a problem there.
	for(
		int i = 1;
		i < argc;
		++i
	)
		engine::log_context().apply(
			fcppt::log::location(
				FCPPT_TEXT("engine")
			)
			/
			fcppt::from_std_string(
				argv[i]
			),
			std::tr1::bind(
				&fcppt::log::object::enable,
				std::tr1::placeholders::_1,
				true
			)
		);
//! [main]
	FCPPT_LOG_DEBUG(
		engine::renderer::logger(),
		fcppt::log::_
			<< FCPPT_TEXT("test")
	)

	FCPPT_LOG_DEBUG(
		engine::audio::logger(),
		fcppt::log::_
			<< FCPPT_TEXT("test")
	)
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
//]
