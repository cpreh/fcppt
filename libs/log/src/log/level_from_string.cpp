//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/enum_from_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/log/level_from_string.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/impl/level_strings.hpp>


fcppt::log::optional_level
fcppt::log::level_from_string(
	fcppt::string const &_name
)
{
	return
		fcppt::enum_from_string<
			fcppt::log::level
		>(
			_name
		);
}
