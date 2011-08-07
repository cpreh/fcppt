//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_DURATION_DECL_HPP_INCLUDED
#define FCPPT_CHRONO_DURATION_DECL_HPP_INCLUDED

#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/chrono/is_duration.hpp>
#include <fcppt/ratio/is_object.hpp>
#include <boost/static_assert.hpp>

namespace fcppt
{
namespace chrono
{

/// A duration is a time span.
/**
 * @tparam Rep dictates the type that the duration will use to represent the values.
 * @tparam Period dictates how this value has to be interpreted.
 * @see fcppt::ratio.
 * Durations can be obtained from a time_point using the time_point::time_since_epoch() function.
*/
template<
	typename Rep,
	typename Period
>
class duration
{
public:
	BOOST_STATIC_ASSERT(
		!is_duration<
			Rep
		>::value
	);

	BOOST_STATIC_ASSERT(
		ratio::is_object<
			Period
		>::value
	);

	BOOST_STATIC_ASSERT(
		Period::num > 0
	);

	typedef Rep rep;
	typedef Period period;

	/// Default constructs a duration
	duration();

	/// Constructs a duration from a compatible internal representation
	/**
	 * For example seconds(10) will result in a duration representing 10 seconds
	*/
	template<
		typename Rep2
	>
	explicit duration(
		Rep2 const &
	);

	/// Constructs a duration from another compatible duration and converts if necessary.
	template<
		typename Rep2,
		typename Period2
	>
	duration(
		duration<
			Rep2,
			Period2
		> const &
	);

	~duration();

	duration(
		duration const &
	);

	duration &
	operator =(
		duration const &
	);

	/// Returns the internal representation
	/**
	 * This is useful if you need the actual integral value
	*/
	rep
	count() const;

	duration
	operator +() const;

	duration
	operator -() const;

	duration &
	operator ++();

	duration
	operator ++(int);

	duration &
	operator --();

	duration
	operator --(int);

	duration &
	operator +=(
		duration const &
	);

	duration &
	operator -=(
		duration const &
	);

	duration &
	operator *=(
		rep const &
	);

	duration &
	operator /=(
		rep const &
	);

	duration &
	operator %=(
		rep const &
	);

	duration &
	operator %=(
		duration const &
	);

	/// The duration with a zero value
	static duration
	zero();

	/// The duration with the minimum value
	static duration
	min();

	/// The duration with the maximum value
	static duration
	max();
private:
	rep rep_;
};

}
}

#endif
