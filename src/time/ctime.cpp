//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/time/ctime.hpp>
#include <fcppt/time/exception.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/text.hpp>
#include <ctime>

fcppt::string const
fcppt::time::ctime(
	std::time_t const time_
)
{
	char const *const ret(
		std::ctime(
			&time_
		)
	);

	if(
		ret == 0
	)
		throw exception(
			FCPPT_TEXT("std::ctime() failed!")
		);
	
	return
		from_std_string(
			ret
		);
}
