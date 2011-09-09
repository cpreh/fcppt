//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[logcontext
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/parameters/with_context.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/output.hpp>
#include <fcppt/log/warning.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/text.hpp>

int
main()
{
	// Create a logger context
	fcppt::log::context context;

	// Create the root logger.
	// It will have the location "::root" in the tree.
	// Note that all loggers are initially disabled until told otherwise.
	fcppt::log::object root(
		fcppt::log::parameters::with_context(
			context,
			fcppt::io::cout,
			fcppt::log::location(
				FCPPT_TEXT("root")
			)
		)
		.level_defaults(
			fcppt::log::level::warning
		)
	);

	// Creat the child logger.
	// It will have the location "::root::child" in the tree.
	fcppt::log::object child(
		fcppt::log::parameters::with_context(
			context,
			fcppt::io::cout,
			fcppt::log::location(
				FCPPT_TEXT("root")
			)
			/
			FCPPT_TEXT("child")
		)
		.level_defaults(
			fcppt::log::level::warning
		)
	);

	// Enable all loggers starting from root.
	context.apply(
		fcppt::log::location(
			FCPPT_TEXT("root")
		),
		std::tr1::bind(
			&fcppt::log::object::enable,
			std::tr1::placeholders::_1,
			true
		)
	);

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
}
//]
