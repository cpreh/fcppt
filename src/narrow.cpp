//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/narrow.hpp>
#include "codecvt.hpp"

std::string const
fcppt::narrow(
	std::wstring const &_string,
	std::locale const &_locale
)
{
	return
		fcppt::codecvt<
			char
		>(
			_string,
			_locale
		);
}
