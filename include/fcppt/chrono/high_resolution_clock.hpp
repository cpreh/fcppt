//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_HIGH_RESOLUTION_CLOCK_HPP_INCLUDED
#define FCPPT_CHRONO_HIGH_RESOLUTION_CLOCK_HPP_INCLUDED

#include <fcppt/chrono/high_resolution_clock_fwd.hpp>
#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/chrono/time_point_fwd.hpp>
#include <fcppt/chrono/rep.hpp>
#include <fcppt/ratio/nano.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace chrono
{

/// Provides a clock with the highest possible resolution.
/**
 * Beware that this clock usually isn't guaranteed to be steady,
 * so it can, for example, wrap around after not too much time.
*/
class high_resolution_clock
{
public:
	typedef chrono::rep rep;

	typedef fcppt::ratio::nano period;

	typedef chrono::duration<
		rep,
		period
	> duration;

	typedef chrono::time_point<
		high_resolution_clock
	> time_point;

	// may be true for windows but can only be detected at runtime
	static bool const is_steady = false;

	FCPPT_SYMBOL
	static time_point
	now();
};

}
}

#endif
