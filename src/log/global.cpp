//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/global.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/global_context.hpp>
#include <fcppt/log/parameters/root.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

fcppt::log::object &
fcppt::log::global()
{
	static object global_(
		parameters::root(
			io::cout
		)
		.prefix(
			FCPPT_TEXT("fcppt")
		)
		.enabled(
			true
		)
		.level(
			log::level::warning
		)
		.context(
			global_context()
		)
		.create()
	);

	return global_;
}
