//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_std_wstring_locale.hpp>
#include <fcppt/string.hpp>
#include <fcppt/public_config.hpp>
#if defined(FCPPT_NARROW_STRING)
#include <fcppt/narrow.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::from_std_wstring_locale(
	std::wstring const &_input,
#if defined(FCPPT_NARROW_STRING)
	std::locale const &_locale
#else
	std::locale const &
#endif
)
{
#if defined(FCPPT_NARROW_STRING)
	return
		fcppt::narrow(
			_input,
			_locale
		);
#else
	return
		_input;
#endif
}
