//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_MACH_TIME_IMPL_HPP_INCLUDED
#define FCPPT_CHRONO_MACH_TIME_IMPL_HPP_INCLUDED

#include "mach_timebase.hpp"
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/chrono/rep.hpp>
#include <boost/rational.hpp>
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
	typedef boost::rational<
		rep
	> rational;

	typedef typename TimePoint::duration duration_;

	typedef typename duration_::period period_;

	struct mach_timebase_info const info(
		mach_timebase()
	);

	return TimePoint(
		duration_(
			boost::rational_cast<
				rep
			>(
				static_cast<
					rep
				>(
					mach_absolute_time()
				)
				*
				rational(
					info.numer,
					info.denom
				)
				/
				rational(
					period_::num,
					period_::den
				)
			)
		)
	);	
}

}

}
}

#endif
