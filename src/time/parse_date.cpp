//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "time_get_parse.hpp"
#include "time_get.hpp"
#include <fcppt/time/parse_date.hpp>

fcppt::io::istream &
fcppt::time::parse_date(
	io::istream &_stream,
	std::tm &_result
)
{
	return
		time::time_get_parse(
			_stream,
			_result,
			&time::time_get::get_date
		);
}
