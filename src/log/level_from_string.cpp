//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/log/exception.hpp>
#include <fcppt/log/level_from_string.hpp>
#include <fcppt/src/log/level_string_array.hpp>
#include <fcppt/src/log/level_strings.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


fcppt::log::level::type
fcppt::log::level_from_string(
	fcppt::string const &_str
)
{
	log::level_string_array const level_strings(
		log::level_strings()
	);

	log::level_string_array::const_iterator const it(
		std::find(
			level_strings.begin(),
			level_strings.end(),
			_str
		)
	);

	if(
		it == level_strings.end()
	)
		throw log::exception(
			FCPPT_TEXT("level_from_string(): \"")
			+ _str
			+ FCPPT_TEXT("\" not found!")
		);

	return
		static_cast<
			level::type
		>(
			std::distance(
				static_cast<
					log::level_string_array const &
				>(
					level_strings
				).begin(),
				it
			)
		);
}
