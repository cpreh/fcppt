//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/iconv.hpp>
#ifndef FCPPT_NARROW_STRING
#include <fcppt/narrow.hpp>
#include <fcppt/widen.hpp>

fcppt::string const
fcppt::iconv(
	std::string const &input
)
{
	return widen(input);
}

std::string const
fcppt::iconv(
	string const &input
)
{
	return narrow(input);
}

#else

fcppt::string const
fcppt::iconv(
	string const &s
)
{
	return s;
}

#endif
