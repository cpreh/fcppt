//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_SYSTEM_CLOCK_HPP_INCLUDED
#define FCPPT_CHRONO_SYSTEM_CLOCK_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/chrono/rep.hpp>
#include <fcppt/chrono/system_clock_fwd.hpp>
#include <fcppt/chrono/time_point_fwd.hpp>
#include <fcppt/ratio/micro.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace chrono
{

/// Provides the system clock.
/**
 * This clock can be used to display the current time.
 * It is not suitable for measuring time differences as the system clock
 * can change anytime without you noticing. For example the user changes
 * the systme clock or a date client updates it.
*/
class system_clock
{
public:
	typedef chrono::rep rep;

	typedef fcppt::ratio::micro period;

	typedef chrono::duration<
		rep,
		period
	> duration;

	typedef chrono::time_point<
		system_clock
	> time_point;

	static bool const is_steady = false;

	FCPPT_SYMBOL static
	time_point
	now();

	/// Convert a time_point into std::time_t
	FCPPT_SYMBOL static
	std::time_t
	to_time_t(
		time_point const &
	);

	/// Convert std::time_t into a time_point
	FCPPT_SYMBOL
	static time_point
	from_time_t(
		std::time_t
	);
};

}
}

#endif
