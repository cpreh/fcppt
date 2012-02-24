//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/format/create_time_stamp.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/time_stamp.hpp>
#include <fcppt/tr1/functional.hpp>


fcppt::log::format::function const
fcppt::log::format::create_time_stamp()
{
	return
		fcppt::log::format::function(
			std::tr1::bind(
				fcppt::log::format::time_stamp,
				std::tr1::placeholders::_1
			)
		);
}
