//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_to_string.hpp>
#include <fcppt/src/log/level_strings.hpp>


fcppt::string const
fcppt::log::level_to_string(
	fcppt::log::level::type const _level
)
{
	return
		fcppt::log::level_strings()[
			static_cast<
				fcppt::log::level_string_array::size_type
			>(
				_level
			)
		];
}
