//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_IMPL_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_IMPL_HPP_INCLUDED

#include <fcppt/strong_typedef_decl.hpp>
#include <fcppt/detail/strong_typedef/cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	typename Tag
>
template<
	typename U
>
fcppt::strong_typedef<
	T,
	Tag
>::strong_typedef(
	U const &_other
)
:
	value_(
		fcppt::detail::strong_typedef_cast<
			T
		>(
			_other
		)
	)
{
}

template<
	typename T,
	typename Tag
>
template<
	typename U
>
fcppt::strong_typedef<
	T,
	Tag
> &
fcppt::strong_typedef<
	T,
	Tag
>::operator=(
	U const &_other
)
{
	value_ =
		fcppt::detail::strong_typedef_cast<
			T
		>(
			_other
		);

	return *this;
}

template<
	typename T,
	typename Tag
>
T const &
fcppt::strong_typedef<
	T,
	Tag
>::get() const
{
	return value_;
}

template<
	typename T,
	typename Tag
>
void
fcppt::strong_typedef<
	T,
	Tag
>::swap(
	fcppt::strong_typedef<
		T,
		Tag
	> &_other
)
{
	using std::swap;

	swap(
		value_,
		_other.value_
	);
}

// doxygen says: warning: no matching class member found for
/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	typename Tag
>
fcppt::strong_typedef<
	T &,
	Tag
>::strong_typedef(
	reference _value
)
:
	value_(
		_value
	)
{
}
/// \endcond

template<
	typename T,
	typename Tag
>
typename fcppt::strong_typedef<
	T &,
	Tag
>::reference
fcppt::strong_typedef<
	T &,
	Tag
>::get() const
{
	return value_;
}

template<
	typename T,
	typename Tag
>
void
fcppt::swap(
	fcppt::strong_typedef<
		T,
		Tag
	> &_a,
	fcppt::strong_typedef<
		T,
		Tag
	> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
