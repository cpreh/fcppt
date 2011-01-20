//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/widen.hpp>
#include "codecvt.hpp"

std::wstring const
fcppt::widen(
	std::string const &_string,
	std::locale const &_locale
)
{
	return
		fcppt::codecvt<
			wchar_t
		>(
			_string,
			_locale
		);
}
