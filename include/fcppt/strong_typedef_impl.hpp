//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_IMPL_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_IMPL_HPP_INCLUDED

#include <fcppt/strong_typedef_decl.hpp>
#include <fcppt/detail/strong_typedef_cast.hpp>

template<
	typename T,
	typename Tag
>
fcppt::strong_typedef<
	T,
	Tag
>::strong_typedef()
:
	value_()
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
>::strong_typedef(
	U const &_other
)
:
	value_(
		detail::strong_typedef_cast<
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
		detail::strong_typedef_cast<
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
T &
fcppt::strong_typedef<
	T,
	Tag
>::get()
{
	return value_;
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
	strong_typedef<
		T,
		Tag
	> &_other
)
{
	std::swap(
		value_,
		_other.value_
	);
}

template<
	typename T,
	typename Tag
>
bool
fcppt::operator<(
	strong_typedef<
		T,
		Tag
	> const &_a,
	strong_typedef<
		T,
		Tag
	> const &_b
)
{
	return
		_a.get() < _b.get();
}

template<
	typename T,
	typename Tag
>
bool
fcppt::operator==(
	strong_typedef<
		T,
		Tag
	> const &_a,
	strong_typedef<
		T,
		Tag
	> const &_b
)
{
	return
		_a.get() == _b.get();
}

template<
	typename T,
	typename Tag
>
bool
fcppt::operator!=(
	strong_typedef<
		T,
		Tag
	> const &_a,
	strong_typedef<
		T,
		Tag
	> const &_b
)
{
	return
		!(_a == _b);
}

template<
	typename T,
	typename Tag
>
void
fcppt::swap(
	strong_typedef<
		T,
		Tag
	> &_a,
	strong_typedef<
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
