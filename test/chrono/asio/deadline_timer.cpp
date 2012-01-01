//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/milliseconds.hpp>
#include <fcppt/chrono/asio/asio.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

bool run = false;

void
run_to_true()
{
	run = true;
}

}

BOOST_AUTO_TEST_CASE(
	chrono_asio_deadline_timer
)
{
	boost::asio::io_service io_service;

	fcppt::chrono::asio::deadline_timer deadline_timer(
		io_service
	);

	deadline_timer.async_wait(
		std::tr1::bind(
			run_to_true
		)
	);

	fcppt::chrono::asio::expires_from_now_any(
		deadline_timer,
		fcppt::chrono::milliseconds(
			10
		)
	);

	io_service.run();

	BOOST_REQUIRE(
		run
	);
}
