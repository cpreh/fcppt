//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/config.hpp>
#include <fcppt/utf8/convert.hpp>
#ifndef FCPPT_STRING_IS_UTF8
#include <fcppt/utf8/facet.hpp>
#include <sstream>
#include <locale>
#include <algorithm>
#include <iterator>
#endif

namespace
{

#ifndef FCPPT_STRING_IS_UTF8
typedef wchar_t ucs4; // TODO: is this right?
//typedef boost::uint32_t ucs4;

std::locale &utf8_locale()
{
	static std::locale global;

	static std::locale ret(
		global,
		new fcppt::utf8::facet()
	);

	return ret;
}

#endif

}

fcppt::string const
fcppt::utf8::convert(
	utf8::string const &s)
{
#if defined(FCPPT_STRING_IS_UTF8)
	return fcppt::string(
		s.begin(),
		s.end()
	);
#else
	std::basic_istringstream<
		ucs4
	> iss(
		fcppt::string(
			s.begin(),
			s.end()
		)
	);

	iss.imbue(
		utf8_locale()
	);

	fcppt::string ret;

	typedef std::istream_iterator<
		ucs4,
		ucs4
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

fcppt::utf8::string const
fcppt::utf8::convert(
	fcppt::string const &s)
{
#if defined(FCPPT_STRING_IS_UTF8)
	return utf8::string(
		s.begin(),
		s.end()
	);
#else
	std::basic_ostringstream<
		ucs4
	> oss;

	oss.imbue(
		utf8_locale()
	);

	std::copy(
		s.begin(),
		s.end(),
		std::ostream_iterator<
			ucs4,
			ucs4
		>(
			oss
		)
	);

	fcppt::string const &ret(
		oss.str()
	);

	return utf8::string(
		ret.begin(),
		ret.end()
	);
#endif
}
