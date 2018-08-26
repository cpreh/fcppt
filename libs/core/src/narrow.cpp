//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/narrow.hpp>
#include <fcppt/impl/codecvt.hpp>
#include <fcppt/impl/codecvt_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


std::string
fcppt::narrow(
	std::wstring const &_string,
	std::locale const &_locale
)
{
	return
		fcppt::impl::codecvt<
			char
		>(
			_string,
			_locale,
			&fcppt::impl::codecvt_type::out
		);
}
