//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[loghelloworld
#include <fcppt/log/object.hpp>
#include <fcppt/log/headers.hpp>
#include <fcppt/log/parameters/root.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

int main()
{
	fcppt::log::object logger_(
		fcppt::log::parameters::root(
			fcppt::io::cout
		)
		.prefix(
			FCPPT_TEXT("mylogger")
		)
		.enabled(
			true
		)
		.level(
			fcppt::log::level::debug
		)
		.create()
	);

	// Outputs: mylogger: Hello World
	FCPPT_LOG_DEBUG(
		logger_,
		fcppt::log::_
			<< FCPPT_TEXT("Hello World")
	);
}
//]
