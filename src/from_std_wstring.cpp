//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_std_wstring.hpp>
#include <fcppt/config.hpp>
#ifdef FCPPT_NARROW_STRING
#include <fcppt/narrow.hpp>
#endif

fcppt::string const
fcppt::from_std_wstring(
	std::wstring const &_input,
#ifdef FCPPT_NARROW_STRING
	std::locale const &_locale
#else
	std::locale const &
#endif
)
{
#ifdef FCPPT_NARROW_STRING
	return
		fcppt::narrow(
			_input,
			_locale
		);
#else
	return _input;
#endif
}
