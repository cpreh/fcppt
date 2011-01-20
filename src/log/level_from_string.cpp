//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "level_strings.hpp"
#include "level_string_array.hpp"
#include <fcppt/log/level_from_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <algorithm>
#include <iterator>

fcppt::log::level::type
fcppt::log::level_from_string(
	string const &str
)
{
	level_string_array const level_strings(
		log::level_strings()
	);

	level_string_array::const_iterator const it(
		std::find(
			level_strings.begin(),
			level_strings.end(),
			str
		)
	);

	if(
		it == level_strings.end()
	)
		throw exception(
			FCPPT_TEXT("level_from_string(): \"")
			+ str
			+ FCPPT_TEXT("\" not found!")
		);

	return
		static_cast<
			level::type
		>(
			std::distance(
				static_cast<
					level_string_array const &
				>(
					level_strings
				).begin(),
				it
			)
		);
}
