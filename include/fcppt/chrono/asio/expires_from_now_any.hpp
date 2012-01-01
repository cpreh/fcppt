//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_ASIO_EXPIRES_FROM_NOW_ANY_HPP_INCLUDED
#define FCPPT_CHRONO_ASIO_EXPIRES_FROM_NOW_ANY_HPP_INCLUDED

#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/chrono/asio/convert_duration.hpp>
#include <fcppt/chrono/asio/deadline_timer.hpp>


namespace fcppt
{
namespace chrono
{
namespace asio
{

template<
	typename Rep,
	typename Period
>
void
expires_from_now_any(
	fcppt::chrono::asio::deadline_timer &_timer,
	fcppt::chrono::duration<
		Rep,
		Period
	> const &_duration
)
{
	_timer.expires_from_now(
		fcppt::chrono::asio::convert_duration(
			_duration
		)
	);
}

}
}
}

#endif
