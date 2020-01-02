//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/time_stamp.hpp>
#include <fcppt/time/localtime.hpp>
#include <fcppt/time/output_tm.hpp>
#include <fcppt/time/std_time.hpp>


fcppt::log::format::function
fcppt::log::format::time_stamp()
{
	return
		fcppt::log::format::function(
			[](
				fcppt::string const &_text
			)
			{
				fcppt::io::ostringstream stream;

				fcppt::time::output_tm(
					stream,
					fcppt::time::localtime(
						fcppt::time::std_time()
					)
				);

				return
					stream.str()
					+
					FCPPT_TEXT(": ")
					+
					_text
					;
			}
		);
}
