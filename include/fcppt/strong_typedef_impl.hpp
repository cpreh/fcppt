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
	t()
{}

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
	U const &u
)
:
	t(
		detail::strong_typedef_cast<
			T
		>(
			u
		)
	)
{}

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
	U const &u
)
{
	t =
		detail::strong_typedef_cast<
			T
		>(
			u
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
	return t;
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
	return t;
}

template<
	typename T,
	typename Tag
>
fcppt::strong_typedef<
	T,
	Tag
>::operator T &()
{
	return t;
}

template<
	typename T,
	typename Tag
>
fcppt::strong_typedef<
	T,
	Tag
>::operator T const &() const
{
	return t;
}


template<
	typename T,
	typename Tag
>
bool
fcppt::strong_typedef<
	T,
	Tag
>::operator < (
	strong_typedef<
		T,
		Tag
	> const &other
) const
{
	return t < other.t;
}

template<
	typename T,
	typename Tag
>
bool
fcppt::strong_typedef<
	T,
	Tag
>::operator == (
	strong_typedef<
		T,
		Tag
	> const &other
) const
{
	return t == other.t;
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
	> &other_
)
{
	std::swap(
		t,
		other_.t
	);
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
	> &a,
	strong_typedef<
		T,
		Tag
	> &b
)
{
	a.swap(b);
}

#endif
