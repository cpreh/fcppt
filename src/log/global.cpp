//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/global.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/parameters/root.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

namespace
{

fcppt::log::object global_(
	fcppt::log::parameters::root(
		fcppt::io::cout
	)
	.prefix(
		FCPPT_TEXT("fcppt")
	)
	.enabled(
		true
	)
	.level(
		fcppt::log::level::warning
	)
	.create()
);

}

fcppt::log::object &
fcppt::log::global()
{
	return global_;
}
