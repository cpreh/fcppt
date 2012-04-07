//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/asio/clock.hpp>
#include <fcppt/chrono/asio/deadline_timer.hpp>
#include <fcppt/chrono/asio/expires_at_any.hpp>
#include <fcppt/chrono/asio/expires_from_now_any.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/chrono/duration.hpp>
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	chrono_asio_deadline_timer_expires_from_now
)
{
FCPPT_PP_POP_WARNING

	boost::asio::io_service io_service;

	fcppt::chrono::asio::deadline_timer deadline_timer(
		io_service
	);

	fcppt::chrono::asio::expires_from_now_any(
		deadline_timer,
		boost::chrono::milliseconds(
			10
		)
	);

	deadline_timer.async_wait(
		std::tr1::bind(
			run_to_true
		)
	);

	io_service.run();

	BOOST_CHECK(
		run
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	chrono_asio_deadline_timer_expires_at
)
{
FCPPT_PP_POP_WARNING

	boost::asio::io_service io_service;

	fcppt::chrono::asio::deadline_timer deadline_timer(
		io_service
	);

	fcppt::chrono::asio::expires_at_any(
		deadline_timer,
		fcppt::chrono::asio::clock::now()
		+
		boost::chrono::milliseconds(
			10
		)
	);

	deadline_timer.async_wait(
		std::tr1::bind(
			run_to_true
		)
	);

	io_service.run();

	BOOST_CHECK(
		run
	);
}
