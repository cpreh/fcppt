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


#ifndef SGE_CHRONO_TIME_POINT_IMPL_HPP_INCLUDED
#define SGE_CHRONO_TIME_POINT_IMPL_HPP_INCLUDED

#include <sge/chrono/time_point_decl.hpp>
#include <sge/chrono/duration_impl.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/static_assert.hpp>

template<
	typename Clock,
	typename Duration
>
sge::chrono::time_point<
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
sge::chrono::time_point<
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
sge::chrono::time_point<
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
typename sge::chrono::time_point<
	Clock,
	Duration
>::duration
sge::chrono::time_point<
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
sge::chrono::time_point<
	Clock,
	Duration
> &
sge::chrono::time_point<
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
sge::chrono::time_point<
	Clock,
	Duration
> &
sge::chrono::time_point<
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
sge::chrono::time_point<
	Clock,
	Duration
>
sge::chrono::time_point<
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
sge::chrono::time_point<
	Clock,
	Duration
>
sge::chrono::time_point<
	Clock,
	Duration
>::max()
{
	return time_point(
		duration::max()
	);
}

#endif
