//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[logcomplex
#include <fcppt/function/object.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/error.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/output.hpp> // needed for the log::_ << syntax
#include <fcppt/log/parameters/inherited.hpp>
#include <fcppt/log/parameters/root.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/text.hpp>
#include <cstdlib>

namespace mylib
{

// define a global log context
fcppt::log::context log_context_;

// define our root logger
fcppt::log::object root_logger_(
	fcppt::log::parameters::root(
		fcppt::io::cout
	)
	.prefix(
		FCPPT_TEXT("mylib")
	)
	.context(
		log_context_
	)
	.level(
		fcppt::log::level::debug
	)
	.enabled(
		false
	)
	.create()
);

// define two subsystem loggers
// they will be initially disabled because the root logger is disabled
namespace subsystem1
{

fcppt::log::object logger_(
	fcppt::log::parameters::inherited(
		root_logger_,
		FCPPT_TEXT("subsystem1")
	)
);

void
test();

}

namespace subsystem2
{

fcppt::log::object logger_(
	fcppt::log::parameters::inherited(
		root_logger_,
		FCPPT_TEXT("subsystem2")
	)
);

void
test();

}

}

void
mylib::subsystem1::test()
{
	FCPPT_LOG_DEBUG(
		logger_,
		fcppt::log::_
			<< FCPPT_TEXT("test!")
	);
}

void
mylib::subsystem2::test()
{
	FCPPT_LOG_ERROR(
		logger_,
		fcppt::log::_
			<< FCPPT_TEXT("test!")
	);
}

int
main(
	int argc,
	char **argv
)
try
{
	// every parameter tells which loggers we want to activate
	// for example: subsystem1 will activate the logger of subsystem1
	for(
		int i = 1;
		i < argc;
		++i
	)
		mylib::log_context_.apply(
			fcppt::log::location(
				FCPPT_TEXT("mylib")
			)
			+
			fcppt::from_std_string(
				argv[i]
			),
			std::tr1::bind(
				&fcppt::log::object::enable,
				std::tr1::placeholders::_1,
				true
			)
		);
	
	mylib::subsystem1::test();

	mylib::subsystem2::test();
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< e.string()
		<< FCPPT_TEXT('\n');
	
	return EXIT_FAILURE;
}
//]
