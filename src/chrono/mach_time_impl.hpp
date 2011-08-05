//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_MACH_TIME_IMPL_HPP_INCLUDED
#define FCPPT_CHRONO_MACH_TIME_IMPL_HPP_INCLUDED

#include "mach_timebase.hpp"
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <mach/mach_time.h>

namespace fcppt
{
namespace chrono
{

namespace
{

template<
	typename TimePoint
>
TimePoint const
mach_time_impl()
{
	typedef typename TimePoint::duration duration_type;

	struct mach_timebase_info const info(
		chrono::mach_timebase()
	);

	return
		TimePoint(
			duration_type(
				static_cast<
					typename duration_type::rep
				>(
					::mach_absolute_time()
					* info.numer
					/ info.denom
				)
			)
		);
}

}

}
}

#endif
