//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/enum/to_string.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_strings.hpp>
#include <fcppt/log/level_to_string.hpp>


fcppt::string
fcppt::log::level_to_string(
	fcppt::log::level const _level
)
{
	return
		fcppt::enum_::to_string(
			_level
		);
}
