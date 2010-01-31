//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_MONOTONIC_CLOCK_HPP_INCLUDED
#define FCPPT_CHRONO_MONOTONIC_CLOCK_HPP_INCLUDED

#include <fcppt/chrono/monotonic_clock_fwd.hpp>
#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/chrono/time_point_fwd.hpp>
#include <fcppt/chrono/rep.hpp>
#include <fcppt/ratio/nano.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace chrono
{

/// Provides a monotonic clock.
/** For two calls to now() in sequence, t1 = now(); t2 = now();,
 * t2 will always be greater than t1.
*/
class monotonic_clock
{
public:
	typedef chrono::rep rep;

	typedef fcppt::ratio::nano period;

	typedef fcppt::chrono::duration<
		rep,
		period
	> duration;

	typedef chrono::time_point<
		monotonic_clock
	> time_point;

	static bool const is_monotonic = true;

	FCPPT_SYMBOL
	static time_point
	now();
};

}
}

#endif
