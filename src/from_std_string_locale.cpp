//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_std_string_locale.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config.hpp>
#if !defined(FCPPT_NARROW_STRING)
#include <fcppt/widen.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


fcppt::string const
fcppt::from_std_string_locale(
	std::string const &_input,
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
	return _input;
#endif
}
