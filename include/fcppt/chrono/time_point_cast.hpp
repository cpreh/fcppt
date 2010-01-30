//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_TIME_POINT_CAST_HPP_INCLUDED
#define FCPPT_CHRONO_TIME_POINT_CAST_HPP_INCLUDED

#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/chrono/duration_cast.hpp>

namespace fcppt
{
namespace chrono
{

template<
	typename ToDuration,
	typename Clock,
	typename Duration
>
time_point<
	Clock,
	ToDuration
>
time_point_cast(
	time_point<
		Clock,
		Duration
	> const &t
)
{
	return time_point<
		Clock,
		ToDuration
	>(
		duration_cast<
			ToDuration
		>(
			t.time_since_epoch()
		)
	);
}

}
}

#endif
