//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_std_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/time/ctime.hpp>
#include <fcppt/time/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::time::ctime(
	std::time_t const _time
)
{
	char const *const ret(
		std::ctime(
			&_time
		)
	);

	if(
		ret
		==
		nullptr
	)
		throw
			fcppt::time::exception{
				FCPPT_TEXT("std::ctime() failed!")
			};

	return
		fcppt::from_std_string(
			ret
		);
}
