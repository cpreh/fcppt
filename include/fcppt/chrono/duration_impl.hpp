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


#ifndef SGE_CHRONO_DURATION_IMPL_HPP_INCLUDED
#define SGE_CHRONO_DURATION_IMPL_HPP_INCLUDED

#include <sge/chrono/duration_decl.hpp>
#include <sge/chrono/duration_cast.hpp>
#include <sge/chrono/duration_values.hpp>
#include <sge/chrono/treat_as_floating_point.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/static_assert.hpp>

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
>::duration()
:
	rep_()
{}

template<
	typename Rep,
	typename Period
>
template<
	typename Rep2
>
sge::chrono::duration<
	Rep,
	Period
>::duration(
	Rep2 const &rep2_
)
:
	rep_(
		rep2_
	)
{
	BOOST_STATIC_ASSERT((
		boost::is_convertible<
			Rep,
			Rep2
		>::value
		&&
		(
		treat_as_floating_point<
			Rep
		>::value
		||
		! treat_as_floating_point<
			Rep2
		>::value
		)
	));
}

template<
	typename Rep,
	typename Period
>
template<
	typename Rep2,
	typename Period2
>
sge::chrono::duration<
	Rep,
	Period
>::duration(
	duration<
		Rep2,
		Period2
	> const &other
)
:
	rep_(
		duration_cast<
			duration
		>(
			other
		).count()
	)
{
	BOOST_STATIC_ASSERT((
		treat_as_floating_point<Rep>::value
		|| ratio_divide<
			Period2,
			Period
		>::type::den == 1
	));
}

template<
	typename Rep,
	typename Period
>

sge::chrono::duration<
	Rep,
	Period
>::~duration()
{}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
>::duration(
	duration const &other
)
:
	rep_(
		other.rep_
	)
{}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
> &
sge::chrono::duration<
	Rep,
	Period
>::operator =(
	duration const &other
)
{
	rep_ = other.rep_;

	return *this;
}

template<
	typename Rep,
	typename Period
>
typename sge::chrono::duration<
	Rep,
	Period
>::rep
sge::chrono::duration<
	Rep,
	Period
>::count() const
{
	return rep_;
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
>
sge::chrono::duration<
	Rep,
	Period
>::operator +() const
{
	return *this;
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
>
sge::chrono::duration<
	Rep,
	Period
>::operator -() const
{
	return duration(
		-rep_
	);
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
> &
sge::chrono::duration<
	Rep,
	Period
>::operator ++()
{
	++rep_;

	return *this;
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
>
sge::chrono::duration<
	Rep,
	Period
>::operator ++(int)
{
	return duration(
		rep_++
	);
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
> &
sge::chrono::duration<
	Rep,
	Period
>::operator --()
{
	--rep_;

	return *this;
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
>
sge::chrono::duration<
	Rep,
	Period
>::operator --(int)
{
	return duration(
		rep_--
	);
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
> &
sge::chrono::duration<
	Rep,
	Period
>::operator +=(
	duration const &other
)
{
	rep_ += other.count();

	return *this;
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
> &
sge::chrono::duration<
	Rep,
	Period
>::operator -=(
	duration const &other
)
{
	rep_ -= other.count();

	return *this;
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
> &
sge::chrono::duration<
	Rep,
	Period
>::operator *=(
	rep const &other
)
{
	rep_ *= other;

	return *this;
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
> &
sge::chrono::duration<
	Rep,
	Period
>::operator /=(
	rep const &other
)
{
	rep_ /= other;

	return *this;
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
>
sge::chrono::duration<
	Rep,
	Period
>::zero()
{
	return duration(
		duration_values<
			Rep
		>::zero()
	);
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
>
sge::chrono::duration<
	Rep,
	Period
>::min()
{
	return duration(
		duration_values<
			Rep
		>::min()
	);
}

template<
	typename Rep,
	typename Period
>
sge::chrono::duration<
	Rep,
	Period
>
sge::chrono::duration<
	Rep,
	Period
>::max()
{
	return duration(
		duration_values<
			Rep
		>::max()
	);
}

#endif
