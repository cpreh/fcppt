//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/default_locale.hpp>
#include <locale>
#include <cstdlib>

namespace
{

std::locale global;

struct init
{
	init();
} instance;

}

std::locale const
fcppt::default_locale()
{
	return global;
}

namespace
{

init::init()
{
	char const *const env(
		std::getenv(
			"LC_ALL"
		)
	);

	if(
		env
	)
		global =
			std::locale(
				env
			);
}

}
