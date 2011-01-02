//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_DURATION_IMPL_HPP_INCLUDED
#define FCPPT_CHRONO_DURATION_IMPL_HPP_INCLUDED

#include <fcppt/chrono/duration_decl.hpp>
#include <fcppt/chrono/duration_cast.hpp>
#include <fcppt/chrono/duration_values.hpp>
#include <fcppt/chrono/treat_as_floating_point.hpp>
#include <fcppt/ratio/divide.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/static_assert.hpp>

template<
	typename Rep,
	typename Period
>
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
>::duration(
	Rep2 const &_rep2
)
:
	rep_(
		_rep2
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
fcppt::chrono::duration<
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
		|| ratio::divide<
			Period2,
			Period
		>::type::den == 1
	));
}

template<
	typename Rep,
	typename Period
>

fcppt::chrono::duration<
	Rep,
	Period
>::~duration()
{}

template<
	typename Rep,
	typename Period
>
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
> &
fcppt::chrono::duration<
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
typename fcppt::chrono::duration<
	Rep,
	Period
>::rep
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
>
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
>
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
> &
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
>
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
> &
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
>
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
> &
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
> &
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
> &
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
> &
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
> &
fcppt::chrono::duration<
	Rep,
	Period
>::operator %=(
	rep const &other
)
{
	rep_ %= other;

	return *this;
}

template<
	typename Rep,
	typename Period
>
fcppt::chrono::duration<
	Rep,
	Period
> &
fcppt::chrono::duration<
	Rep,
	Period
>::operator %=(
	duration const &other
)
{
	rep_ %= other.count();

	return *this;
}

template<
	typename Rep,
	typename Period
>
fcppt::chrono::duration<
	Rep,
	Period
>
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
>
fcppt::chrono::duration<
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
fcppt::chrono::duration<
	Rep,
	Period
>
fcppt::chrono::duration<
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
