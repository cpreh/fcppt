//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_STEADY_CLOCK_HPP_INCLUDED
#define FCPPT_CHRONO_STEADY_CLOCK_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/chrono/rep.hpp>
#include <fcppt/chrono/steady_clock_fwd.hpp>
#include <fcppt/chrono/time_point_fwd.hpp>
#include <fcppt/ratio/nano.hpp>


namespace fcppt
{
namespace chrono
{

/// Provides a steady clock.
/**
 * For two calls to now() in sequence, t1 = now(); t2 = now();,
 * t2 will always be greater than t1. Also, the intervals of
 * time will always be the same and cannot be adjusted.
*/
class steady_clock
{
public:
	typedef chrono::rep rep;

	typedef fcppt::ratio::nano period;

	typedef fcppt::chrono::duration<
		rep,
		period
	> duration;

	typedef chrono::time_point<
		steady_clock
	> time_point;

	static bool const is_steady = true;

	FCPPT_SYMBOL
	static time_point
	now();
};

}
}

#endif
