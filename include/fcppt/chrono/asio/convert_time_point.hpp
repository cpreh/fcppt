//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_ASIO_CONVERT_TIME_POINT_HPP_INCLUDED
#define FCPPT_CHRONO_ASIO_CONVERT_TIME_POINT_HPP_INCLUDED

#include <fcppt/chrono/asio/clock.hpp>
#include <fcppt/chrono/asio/duration.hpp>
#include <fcppt/chrono/asio/time_point.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/chrono/time_point.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace chrono
{
namespace asio
{

template<
	typename Duration
>
fcppt::chrono::asio::time_point const
convert_time_point(
	boost::chrono::time_point<
		fcppt::chrono::asio::clock,
		Duration
	> const &_time_point
)
{
	return
		boost::chrono::time_point_cast<
			fcppt::chrono::asio::duration
		>(
			_time_point
		);
}

}
}
}

#endif
