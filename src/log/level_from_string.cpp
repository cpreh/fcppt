//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/log/exception.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_from_string.hpp>
#include <fcppt/src/log/level_string_array.hpp>
#include <fcppt/src/log/level_strings.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


fcppt::log::level
fcppt::log::level_from_string(
	fcppt::string const &_name
)
{
	fcppt::log::level_string_array const level_strings(
		fcppt::log::level_strings()
	);

	fcppt::log::level_string_array::const_iterator const it(
		std::find(
			level_strings.cbegin(),
			level_strings.cend(),
			_name
		)
	);

	if(
		it == level_strings.end()
	)
		throw fcppt::log::exception(
			FCPPT_TEXT("level_from_string(): \"")
			+ _name
			+ FCPPT_TEXT("\" not found!")
		);

	return
		fcppt::cast::int_to_enum<
			fcppt::log::level
		>(
			std::distance(
				level_strings.cbegin(),
				it
			)
		);
}
