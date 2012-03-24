//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[chronoasio
#include <fcppt/chrono/asio/deadline_timer.hpp>
#include <fcppt/chrono/asio/expires_from_now_any.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/chrono/duration.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
	boost::asio::io_service io_service;

	// use fcppt's deadline_timer so it can be used with chrono
	fcppt::chrono::asio::deadline_timer timer(
		io_service
	);

	// use this helper function to let the timer fire in one second
	fcppt::chrono::asio::expires_from_now_any(
		timer,
		boost::chrono::seconds(1)
	);

	io_service.run();
}
//]
