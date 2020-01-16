//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_std_string_locale.hpp>
#include <fcppt/public_config.hpp>
#include <fcppt/string.hpp>
#if !defined(FCPPT_NARROW_STRING)
#include <fcppt/widen.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string_view>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::from_std_string_locale(
	std::string_view const &_input,
	std::locale const &
#if !defined(FCPPT_NARROW_STRING)
		_locale
#endif
)
{
#if !defined(FCPPT_NARROW_STRING)
	return
		fcppt::widen(
			_input,
			_locale
		);
#else
	return
		fcppt::string{
			_input
		};
#endif
}
