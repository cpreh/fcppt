//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/to_std_string.hpp>
#include <fcppt/config.hpp>
#ifndef FCPPT_NARROW_STRING
#include <fcppt/narrow.hpp>
#endif

std::string const
fcppt::to_std_string(
	string const &_input,
	std::locale const &
#ifndef FCPPT_NARROW_STRING
		_locale
#endif
)
{
#ifndef FCPPT_NARROW_STRING
	return
		fcppt::narrow(
			_input,
			_locale
		);
#else
	return _input;
#endif
}
