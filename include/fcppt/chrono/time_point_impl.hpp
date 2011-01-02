//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_TIME_POINT_IMPL_HPP_INCLUDED
#define FCPPT_CHRONO_TIME_POINT_IMPL_HPP_INCLUDED

#include <fcppt/chrono/time_point_decl.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/static_assert.hpp>

template<
	typename Clock,
	typename Duration
>
fcppt::chrono::time_point<
	Clock,
	Duration
>::time_point()
:
	d_(
		duration::zero()
	)
{}

template<
	typename Clock,
	typename Duration
>
fcppt::chrono::time_point<
	Clock,
	Duration
>::time_point(
	duration const &other
)
:
	d_(
		other
	)
{}

template<
	typename Clock,
	typename Duration
>
template<
	typename Duration2
>
fcppt::chrono::time_point<
	Clock,
	Duration
>::time_point(
	time_point<
		clock,
		Duration2
	> const &other
)
:
	d_(
		other.time_since_epoch()
	)
{
	BOOST_STATIC_ASSERT((
		boost::is_convertible<
			Duration2,
			duration
		>::value
	));
}

template<
	typename Clock,
	typename Duration
>
typename fcppt::chrono::time_point<
	Clock,
	Duration
>::duration
fcppt::chrono::time_point<
	Clock,
	Duration
>::time_since_epoch() const
{
	return d_;
}

template<
	typename Clock,
	typename Duration
>
fcppt::chrono::time_point<
	Clock,
	Duration
> &
fcppt::chrono::time_point<
	Clock,
	Duration
>::operator +=(
	duration const &other
)
{
	d_ += other;

	return *this;
}

template<
	typename Clock,
	typename Duration
>
fcppt::chrono::time_point<
	Clock,
	Duration
> &
fcppt::chrono::time_point<
	Clock,
	Duration
>::operator -=(
	duration const &other
)
{
	d_ -= other;

	return *this;
}

template<
	typename Clock,
	typename Duration
>
fcppt::chrono::time_point<
	Clock,
	Duration
>
fcppt::chrono::time_point<
	Clock,
	Duration
>::min()
{
	return time_point(
		duration::min()
	);
}

template<
	typename Clock,
	typename Duration
>
fcppt::chrono::time_point<
	Clock,
	Duration
>
fcppt::chrono::time_point<
	Clock,
	Duration
>::max()
{
	return time_point(
		duration::max()
	);
}

#endif
