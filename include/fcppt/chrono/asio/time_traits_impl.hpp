//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_ASIO_TIME_TRAITS_IMPL_HPP_INCLUDED
#define FCPPT_CHRONO_ASIO_TIME_TRAITS_IMPL_HPP_INCLUDED

#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/chrono/time_point_arithmetic.hpp>
#include <fcppt/chrono/time_point_comparison.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/chrono/asio/time_traits_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <fcppt/config/external_end.hpp>


inline
boost::asio::time_traits<
	fcppt::chrono::asio::tag
>::time_type const
boost::asio::time_traits<
	fcppt::chrono::asio::tag
>::now()
{
	return
		clock::now();
}

inline
boost::asio::time_traits<
	fcppt::chrono::asio::tag
>::time_type const
boost::asio::time_traits<
	fcppt::chrono::asio::tag
>::add(
	time_type const &_time,
	duration_type const &_duration
)
{
	return
		_time + _duration;
}

inline
boost::asio::time_traits<
	fcppt::chrono::asio::tag
>::duration_type const
boost::asio::time_traits<
	fcppt::chrono::asio::tag
>::subtract(
	time_type const &_left,
	time_type const &_right
)
{
	return
		_left - _right;
}

inline
bool
boost::asio::time_traits<
	fcppt::chrono::asio::tag
>::less_than(
	time_type const &_left,
	time_type const &_right
)
{
	return
		_left < _right;
}

inline
boost::posix_time::time_duration const
boost::asio::time_traits<
	fcppt::chrono::asio::tag
>::to_posix_duration(
	duration_type const &_duration
)
{
	typedef boost::date_time::subsecond_duration<
		boost::posix_time::time_duration,
		duration_type::period::den
	> posix_type;

	return
		posix_type(
			_duration.count()
		);
}

#endif
