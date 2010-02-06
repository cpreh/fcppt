//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_CLOCK_GETTIME_IMPL_HPP_INCLUDED
#define FCPPT_CHRONO_CLOCK_GETTIME_IMPL_HPP_INCLUDED

#include "unsigned_type.hpp"
#include <fcppt/chrono/clock_failure.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/chrono/rep.hpp>
#include <fcppt/text.hpp>
#include <time.h>

namespace fcppt
{
namespace chrono
{

template<
	typename TimePoint
>
TimePoint const
clock_gettime_impl(
	clockid_t const clock_
)
{
	struct timespec tp;

	if(
		clock_gettime(
			clock_,
			&tp
		) != 0
	)
		throw clock_failure(
			FCPPT_TEXT("clock_gettime failed")
		);

	typedef typename TimePoint::duration duration_;

	return TimePoint(
		duration_(
			static_cast<
				unsigned_type<
					rep
				>::type
			>(
				tp.tv_sec
			)
			* 1000000000UL
			+ static_cast<
				unsigned long
			>(
				tp.tv_nsec
			)
		)
	);
}

}
}

#endif
