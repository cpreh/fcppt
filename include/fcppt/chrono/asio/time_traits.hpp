//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_ASIO_TIME_TRAITS_HPP_INCLUDED
#define FCPPT_CHRONO_ASIO_TIME_TRAITS_HPP_INCLUDED

#include <fcppt/chrono/asio/clock.hpp>
#include <fcppt/chrono/asio/tag.hpp>
#include <fcppt/symbol.hpp>
#include <boost/asio/time_traits.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>

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

	typedef clock::time_point time_type;
	
	typedef clock::duration duration_type;

	FCPPT_SYMBOL
	static time_type const
	now();

	FCPPT_SYMBOL
	static time_type const
	add(
		time_type const &,
		duration_type const &
	);

	FCPPT_SYMBOL
	static duration_type const
	subtract(
		time_type const &,
		time_type const &
	);

	FCPPT_SYMBOL
	static bool
	less_than(
		time_type const &,
		time_type const &
	);

	FCPPT_SYMBOL
	static boost::posix_time::time_duration const
	to_posix_duration(
		duration_type const &
	);
};

}
}

#endif
