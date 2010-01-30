//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_DURATION_DECL_HPP_INCLUDED
#define FCPPT_CHRONO_DURATION_DECL_HPP_INCLUDED

#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/chrono/is_duration.hpp>
#include <fcppt/ratio.hpp>
#include <boost/static_assert.hpp>

namespace fcppt
{
namespace chrono
{

template<
	typename Rep,
	typename Period
>
class duration {
public:
	BOOST_STATIC_ASSERT(
		!is_duration<
			Rep
		>::value
	);

	BOOST_STATIC_ASSERT(
		is_ratio<
			Period
		>::value
	);

	BOOST_STATIC_ASSERT(
		Period::num > 0
	);

	typedef Rep rep;
	typedef Period period;

	duration();

	template<
		typename Rep2
	>
	explicit duration(
		Rep2 const &
	);

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

	static duration
	zero();

	static duration
	min();

	static duration
	max();
private:
	rep rep_;
};

}
}

#endif
