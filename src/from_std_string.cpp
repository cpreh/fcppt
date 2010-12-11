//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_std_string.hpp>
#include <fcppt/config.hpp>
#ifndef FCPPT_NARROW_STRING
#include <fcppt/widen.hpp>
#endif

fcppt::string const
fcppt::from_std_string(
	std::string const &_input,
	std::locale const &
#ifndef FCPPT_NARROW_STRING
		_locale
#endif
)
{
#ifndef FCPPT_NARROW_STRING
	return
		fcppt::widen(
			_input,
			_locale
		);
#else
	return _input;
#endif
}
