//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/utf8/from_fcppt_string.hpp>
#include <fcppt/config.hpp>
#if !defined(FCPPT_STRING_IS_UTF8)
#include "locale.hpp"
#include "ucs4.hpp"
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fcppt/config/external_end.hpp>
#endif

fcppt::utf8::string const
fcppt::utf8::from_fcppt_string(
	fcppt::string const &_input
)
{
#if defined(FCPPT_STRING_IS_UTF8)
	return
		utf8::string(
			_input.begin(),
			_input.end()
		);
#else
	std::basic_ostringstream<
		utf8::ucs4
	> oss;

	oss.imbue(
		utf8::locale()
	);

	std::copy(
		_input.begin(),
		_input.end(),
		std::ostream_iterator<
			utf8::ucs4,
			utf8::ucs4
		>(
			oss
		)
	);

	fcppt::string const &ret(
		oss.str()
	);

	return
		utf8::string(
			ret.begin(),
			ret.end()
		);
#endif
}
