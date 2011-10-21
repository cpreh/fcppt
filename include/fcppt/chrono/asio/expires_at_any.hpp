//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_ASIO_EXPIRES_AT_ANY_HPP_INCLUDED
#define FCPPT_CHRONO_ASIO_EXPIRES_AT_ANY_HPP_INCLUDED

#include <fcppt/chrono/time_point_fwd.hpp>
#include <fcppt/chrono/asio/clock.hpp>
#include <fcppt/chrono/asio/convert_time_point.hpp>
#include <fcppt/chrono/asio/deadline_timer.hpp>


namespace fcppt
{
namespace chrono
{
namespace asio
{

template<
	typename Duration
>
void
expires_at_any(
	fcppt::chrono::asio::deadline_timer &_timer,
	fcppt::chrono::time_point<
		fcppt::chrono::asio::clock,
		Duration
	> const &_time_point
)
{
	_timer.expires_at(
		fcppt::chrono::asio::convert_time_point(
			_time_point
		)
	);
}

}
}
}

#endif
