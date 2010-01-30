/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef FCPPT_CHRONO_CLOCK_GETTIME_IMPL_HPP_INCLUDED
#define FCPPT_CHRONO_CLOCK_GETTIME_IMPL_HPP_INCLUDED

#include <fcppt/chrono/clock_failure.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/chrono/common_type.hpp>
#include <fcppt/chrono/rep.hpp>
#include <fcppt/text.hpp>
#include <boost/type_traits/make_unsigned.hpp>
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

	typedef common_type<
		boost::make_unsigned<
			time_t
		>::type,
		rep
	>::type unsigned_type;

	return TimePoint(
		duration_(
			static_cast<
				unsigned_type
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
