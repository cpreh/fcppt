//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_std_string.hpp>
#include <fcppt/config.h>
#ifndef FCPPT_NARROW_STRING
#include <fcppt/widen.hpp>
#endif

fcppt::string const
fcppt::from_std_string(
	std::string const &input
)
{
#ifndef FCPPT_NARROW_STRING
	return widen(input);
#else
	return input;
#endif
}
