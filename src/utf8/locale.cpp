//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "locale.hpp"
#include <fcppt/config.hpp>
#ifndef FCPPT_STRING_IS_UTF8
#include <fcppt/utf8/facet.hpp>
#include <locale>

namespace
{

struct init
{
	init()
	:
		locale_(
			std::locale(),
			new fcppt::utf8::facet()
		)
	{
	}

	std::locale locale_;
} global;

}

std::locale &
utf8_locale()
{
	return global.locale_;
}
#endif
