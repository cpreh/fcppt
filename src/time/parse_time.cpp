//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "time_get_parse.hpp"
#include "time_get.hpp"
#include <fcppt/time/parse_time.hpp>

fcppt::io::istream &
fcppt::time::parse_time(
	io::istream &stream,
	std::tm &result
)
{
	return
		time::time_get_parse(
			stream,
			result,
			&time::time_get::get_time
		);
}
