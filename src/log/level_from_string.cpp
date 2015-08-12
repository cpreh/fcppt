//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/log/level_from_string.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/impl/level_string_array.hpp>
#include <fcppt/log/impl/level_strings.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


fcppt::log::optional_level
fcppt::log::level_from_string(
	fcppt::string const &_name
)
{
	fcppt::log::impl::level_string_array const level_strings(
		fcppt::log::impl::level_strings()
	);

	// TODO: Make an algorithm for this
	fcppt::log::impl::level_string_array::const_iterator const it(
		std::find(
			level_strings.cbegin(),
			level_strings.cend(),
			_name
		)
	);

	return
		it
		==
		level_strings.end()
		?
			fcppt::log::optional_level()
		:
		fcppt::log::optional_level(
			fcppt::cast::int_to_enum<
				fcppt::log::level
			>(
				std::distance(
					level_strings.cbegin(),
					it
				)
			)
		);
}
