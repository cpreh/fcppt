//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/widen.hpp>
#include <fcppt/impl/codecvt.hpp>
#include <fcppt/impl/codecvt_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


std::wstring
fcppt::widen(
	std::string const &_string,
	std::locale const &_locale
)
{
	return
		fcppt::impl::codecvt<
			wchar_t
		>(
			_string,
			_locale,
			&fcppt::impl::codecvt_type::in
		);
}
