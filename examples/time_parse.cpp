//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[time_parse
#include <fcppt/time/parse_time.hpp>
#include <fcppt/time/parse_date.hpp>
#include <fcppt/io/istringstream.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>

int
main()
{
	fcppt::io::istringstream stream(
		fcppt::string(
			FCPPT_TEXT("12/08/2009")
		)
	);

	std::tm cur_tm;

	if(
		!fcppt::time::parse_date(
			stream,
			cur_tm
		)
	)
		fcppt::io::cerr()
			<< FCPPT_TEXT("Parsing of date failed.\n");
	else
		fcppt::io::cout()
			<< FCPPT_TEXT("Date parsed is: day = ")
			<< cur_tm.tm_mday
			<< FCPPT_TEXT(", month = ")
			<< cur_tm.tm_mon
			<< FCPPT_TEXT(", year = ")
			<< cur_tm.tm_year
			<< FCPPT_TEXT('\n');

	stream.clear();

	stream.str(
		fcppt::string(
			FCPPT_TEXT("15:12:05")
		)
	);

	if(
		!fcppt::time::parse_time(
			stream,
			cur_tm
		)
	)
		fcppt::io::cerr()
			<< FCPPT_TEXT("Parsing of time failed.\n");
	else
		fcppt::io::cout()
			<< FCPPT_TEXT("Time parsed is: hour = ")
			<< cur_tm.tm_hour
			<< FCPPT_TEXT(", minute = ")
			<< cur_tm.tm_min
			<< FCPPT_TEXT(", second = ")
			<< cur_tm.tm_sec
			<< FCPPT_TEXT('\n');
}

//]
