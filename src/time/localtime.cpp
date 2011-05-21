//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/time/localtime.hpp>
#include <ctime>

std::tm const
fcppt::time::localtime(
	std::time_t const _time
)
{
	return
		*std::localtime(
			&_time
		);
}
