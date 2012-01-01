//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_TIME_POINT_DECL_HPP_INCLUDED
#define FCPPT_CHRONO_TIME_POINT_DECL_HPP_INCLUDED

#include <fcppt/chrono/duration_decl.hpp>
#include <fcppt/chrono/time_point_fwd.hpp>


namespace fcppt
{
namespace chrono
{

/// Represents a given point in time, measured by a Clock's now() function.
/**
 * @tparam Clock is the type of the clock from where the time_point was obtained.
 * @tparam Duration is the associated duration.
 * durations can be added to or subtracted from time_points to obtain a
 * time_point further in the future or in the past.
 * Two time_points can be subtracted to get the difference between them (as a duration).
 * time_since_epoch() directly converts the time_point into a duration, using
 * the clocks beginning time as a second time_point.
*/
template<
	typename Clock,
	typename Duration
>
class time_point
{
public:
	typedef Clock clock;
	typedef Duration duration;
	typedef typename duration::rep rep;
	typedef typename duration::period period;

	time_point();

	/// Constructs a time_point from a duration.
	/**
	 * This duration is interpreted as if it were obtained from time_since_epoch().
	*/
	explicit time_point(
		duration const &
	);

	/// Constructs a time_point from a compatible time_point.
	/**
	 * This may convert if necessary.
	*/
	template<
		typename Duration2
	>
	time_point(
		time_point<
			clock,
			Duration2
		> const &
	);

	/// Returns the duration from the beginning of the Clock to this time_point
	duration
	time_since_epoch() const;

	time_point &
	operator +=(
		duration const &
	);

	time_point &
	operator -=(
		duration const &
	);

	/// The minimal time_point
	static time_point
	min();

	/// The maximal time_point
	static time_point
	max();
private:
	duration d_;
};

}
}

#endif
