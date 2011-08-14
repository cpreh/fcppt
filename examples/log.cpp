//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assert/error.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/info.hpp>
#include <fcppt/log/global.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/output.hpp>
#include <fcppt/log/parameters/root.hpp>
#include <fcppt/log/parameters/inherited.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <cstdlib>

int main()
try
{
	fcppt::log::context context_;

	fcppt::log::object logger(
		fcppt::log::parameters::root(
			fcppt::io::cout
		)
		.enabled(
			true
		)
		.context(
			context_
		)
		.prefix(
			FCPPT_TEXT("fcppt")
		)
		.level(
			fcppt::log::level::debug
		)
		.create()
	);

	fcppt::log::object child_logger(
		fcppt::log::parameters::inherited(
			logger,
			FCPPT_TEXT("child")
		)
	);

	fcppt::log::object *const ref(
		context_.find(
			logger.context_location().location()
		)
	);

	FCPPT_ASSERT_ERROR(
		ref != 0
	);

	FCPPT_LOG_INFO(
		*ref,
		fcppt::log::_
			<< FCPPT_TEXT("test output!")
	);

	fcppt::log::object *const child_ref(
		context_.find(
			fcppt::log::location(
				FCPPT_TEXT("fcppt")
			)
			+ FCPPT_TEXT("child")
		)
	);

	FCPPT_ASSERT_ERROR(
		child_ref != 0
	);

	fcppt::io::cout
		<< FCPPT_TEXT("location of child: ")
		<< child_ref->context_location().location().string()
		<< FCPPT_TEXT('\n');

	FCPPT_LOG_INFO(
		*child_ref,
		fcppt::log::_
			<< FCPPT_TEXT("child output!")
	);

	context_.apply(
		logger.context_location().location(),
		std::tr1::bind(
			&fcppt::log::object::enable,
			std::tr1::placeholders::_1,
			false
		)
	);

	FCPPT_LOG_INFO(
		*child_ref,
		fcppt::log::_
			<< FCPPT_TEXT("shouldn't be shown!")
	);
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
