//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/src/log/level_string_array.hpp>
#include <fcppt/src/log/level_strings.hpp>


fcppt::log::level_string_array const
fcppt::log::level_strings()
{
	level_string_array const ret = {{
		FCPPT_TEXT("verbose"),
		FCPPT_TEXT("debug"),
		FCPPT_TEXT("info"),
		FCPPT_TEXT("warning"),
		FCPPT_TEXT("error"),
		FCPPT_TEXT("fatal")
	}};

	return ret;
}
