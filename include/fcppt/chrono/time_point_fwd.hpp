//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_TIME_POINT_FWD_HPP_INCLUDED
#define FCPPT_CHRONO_TIME_POINT_FWD_HPP_INCLUDED

namespace fcppt
{
namespace chrono
{

template<
	typename Clock,
	typename Duration
		= typename Clock::duration
>
class time_point;

}
}

#endif
