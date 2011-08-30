//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/thread/sleep.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/chrono/convert/to_boost_duration.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/thread/thread.hpp>
#include <fcppt/config/external_end.hpp>

void
fcppt::thread::sleep(
	thread::sleep_duration const &_duration
)
{
	boost::this_thread::sleep(
		chrono::convert::to_boost_duration(
			_duration
		)
	);
}
