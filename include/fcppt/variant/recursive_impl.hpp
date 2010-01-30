//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_RECURSIVE_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_RECURSIVE_IMPL_HPP_INCLUDED

#include <fcppt/variant/recursive_decl.hpp>
#include <algorithm>

template<
	typename T
>
fcppt::variant::recursive<T>::recursive(
	T const &other
)
:
	rep_(
		copy(
			other
		)
	)
{
}

template<
	typename T
>
fcppt::variant::recursive<T>::recursive(
	recursive const &other
)
:
	rep_(
		copy(
			other.get()
		)
	)
{
}

template<
	typename T
>
fcppt::variant::recursive<T> &
fcppt::variant::recursive<T>::operator =(
	T const &other
)
{
	*rep_ = other;

	return *this;
}

template<
	typename T
>
fcppt::variant::recursive<T> &
fcppt::variant::recursive<T>::operator =(
	recursive const &other
)
{
	*rep_ = other.get();

	return *this;
}

template<
	typename T
>
fcppt::variant::recursive<T>::~recursive()
{
	delete rep_;
}

template<
	typename T
>
void
fcppt::variant::recursive<T>::swap(
	recursive &other
)
{
	std::swap(
		rep_,
		other.rep_
	);
}

template<
	typename T
>
T &
fcppt::variant::recursive<T>::get() const
{
	return *rep_;
}

template<
	typename T
>
T *
fcppt::variant::recursive<T>::copy(
	T const &other
)
{
	return new T(other);
}

template<
	typename T
>
void
fcppt::variant::swap(
	recursive<T> &a,
	recursive<T> &b
)
{
	a.swap(
		b
	);
}

#endif
