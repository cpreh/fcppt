//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "level_strings.hpp"
#include <fcppt/log/level_to_string.hpp>

fcppt::string const
fcppt::log::level_to_string(
	level::type const level_
)
{
	return
		level_strings()[
			static_cast<
				level_string_array::size_type
			>(
				level_
			)
		];
}
