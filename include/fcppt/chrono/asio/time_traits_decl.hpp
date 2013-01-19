//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_ASIO_TIME_TRAITS_DECL_HPP_INCLUDED
#define FCPPT_CHRONO_ASIO_TIME_TRAITS_DECL_HPP_INCLUDED

#include <fcppt/chrono/asio/clock.hpp>
#include <fcppt/chrono/asio/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/asio/time_traits.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <fcppt/config/external_end.hpp>


namespace boost
{
namespace asio
{

template<>
struct time_traits<
	fcppt::chrono::asio::tag
>
{
	typedef fcppt::chrono::asio::clock clock;

	typedef time_traits::clock::time_point time_type;

	typedef time_traits::clock::duration duration_type;

	static time_type const
	now();

	static time_type const
	add(
		time_type const &,
		duration_type const &
	);

	static duration_type const
	subtract(
		time_type const &,
		time_type const &
	);

	static bool
	less_than(
		time_type const &,
		time_type const &
	);

	static boost::posix_time::time_duration const
	to_posix_duration(
		duration_type const &
	);
};

}
}

#endif
