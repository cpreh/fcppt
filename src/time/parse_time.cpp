//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/istream.hpp>
#include <fcppt/src/time/time_get.hpp>
#include <fcppt/src/time/time_get_parse.hpp>
#include <fcppt/time/parse_time.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>


fcppt::io::istream &
fcppt::time::parse_time(
	io::istream &_stream,
	std::tm &_result
)
{
	return
		time::time_get_parse(
			_stream,
			_result,
			&time::time_get::get_time
		);
}
