//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/_.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/tree_function.hpp>
#include <fcppt/log/warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


int
main()
{
//! [declare_context]
	// Create a logger context
	fcppt::log::context context;
//! [declare_context]

//! [declare_root_logger]
	// Create the root logger.
	// It will have the location "::root" in the tree.
	// Note that all loggers are initially disabled until told otherwise.
	fcppt::log::object root(
		fcppt::log::parameters(
			fcppt::io::cout(),
			fcppt::log::level::warning
		)
		.context_location(
			context,
			fcppt::log::location(
				FCPPT_TEXT("root")
			)
		)
	);
//! [declare_root_logger]

//! [declare_child_logger]
	// Create the child logger.
	// It will have the location "::root::child" in the tree.
	fcppt::log::object child(
		fcppt::log::parameters(
			fcppt::io::cout(),
			fcppt::log::level::warning
		)
		.context_location(
			context,
			fcppt::log::location(
				FCPPT_TEXT("root")
			)
			/
			FCPPT_TEXT("child")
		)
	);
//! [declare_child_logger]

//! [enable_loggers]
	// Enable all loggers starting from root.
	context.apply(
		fcppt::log::location(
			FCPPT_TEXT("root")
		),
		fcppt::log::tree_function{
			std::bind(
				&fcppt::log::object::enable,
				std::placeholders::_1,
				true
			)
		}
	);
//! [enable_loggers]

//! [print]
	FCPPT_LOG_WARNING(
		root,
		fcppt::log::_
			<< FCPPT_TEXT("Print from root.")
	);

	FCPPT_LOG_WARNING(
		child,
		fcppt::log::_
			<< FCPPT_TEXT("Print from child.")
	);
//! [print]
}
//]
