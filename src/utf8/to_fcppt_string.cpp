//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/utf8/to_fcppt_string.hpp>
#include <fcppt/config.hpp>
#if !defined(FCPPT_STRING_IS_UTF8)
#include <fcppt/src/utf8/locale.hpp>
#include <fcppt/src/utf8/ucs4.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fcppt/config/external_end.hpp>
#endif

fcppt::string const
fcppt::utf8::to_fcppt_string(
	utf8::string const &_input
)
{
#if defined(FCPPT_STRING_IS_UTF8)
	return
		fcppt::string(
			_input.begin(),
			_input.end()
		);
#else
	std::basic_istringstream<
		utf8::ucs4
	> iss(
		fcppt::string(
			_input.begin(),
			_input.end()
		)
	);

	iss.imbue(
		utf8::locale()
	);

	fcppt::string ret;

	typedef std::istream_iterator<
		utf8::ucs4,
		utf8::ucs4
	> istream_iterator;

	std::copy(
		istream_iterator(
			iss
		),
		istream_iterator(),
		std::back_inserter(
			ret
		)
	);

	return ret;
#endif
}
