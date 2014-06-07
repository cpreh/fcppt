//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/format/create_time_stamp.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/time_stamp.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


fcppt::log::format::function const
fcppt::log::format::create_time_stamp()
{
	return
		fcppt::log::format::function(
			std::bind(
				fcppt::log::format::time_stamp,
				std::placeholders::_1
			)
		);
}
