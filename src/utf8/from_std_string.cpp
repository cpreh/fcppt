//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/utf8/from_std_string.hpp>
#include <fcppt/config.hpp>
#if defined(FCPPT_STRING_IS_UTF8) && defined(FCPPT_NARROW_STRING)
#define FCPPT_STRING_TO_UTF8_DIRECT
#endif
#include <fcppt/utf8/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>
#if !defined(FCPPT_STRING_TO_UTF8_DIRECT)
#include <fcppt/utf8/from_fcppt_string.hpp>
#include <fcppt/from_std_string.hpp>
#endif

fcppt::utf8::string const
fcppt::utf8::from_std_string(
	std::string const &_input
)
{
	return
#if defined(FCPPT_STRING_TO_UTF8_DIRECT)
		fcppt::utf8::string(
			_input.begin(),
			_input.end()
		);
#else
		fcppt::utf8::from_fcppt_string(
			fcppt::from_std_string(
				_input
			)
		);
#endif
}
