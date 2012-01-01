//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/to_std_wstring.hpp>
#include <fcppt/config.hpp>
#ifdef FCPPT_NARROW_STRING
#include <fcppt/widen.hpp>
#endif

std::wstring const
fcppt::to_std_wstring(
	string const &_input,
#ifdef FCPPT_NARROW_STRING
	std::locale const &_locale
#else
	std::locale const &
#endif
)
{
#ifdef FCPPT_NARROW_STRING
	return
		fcppt::widen(
			_input,
			_locale
		);
#else
	return _input;
#endif
}
