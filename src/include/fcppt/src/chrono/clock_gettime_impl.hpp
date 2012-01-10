//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_CHRONO_CLOCK_GETTIME_IMPL_HPP_INCLUDED
#define FCPPT_SRC_CHRONO_CLOCK_GETTIME_IMPL_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/chrono/clock_failure.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <time.h>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace chrono
{

template<
	typename TimePoint
>
TimePoint const
clock_gettime_impl(
	clockid_t const _clock
)
{
	struct timespec tp;

	if(
		::clock_gettime(
			_clock,
			&tp
		) != 0
	)
		throw chrono::clock_failure(
			FCPPT_TEXT("clock_gettime failed")
		);

	typedef typename TimePoint::duration duration;

	return
		TimePoint(
			duration(
				tp.tv_sec
				*
				1000000000L
				+
				tp.tv_nsec
			)
		);
	}

}
}

#endif
