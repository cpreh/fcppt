//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_RECURSIVE_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_RECURSIVE_IMPL_HPP_INCLUDED

#include <fcppt/variant/recursive_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


template<
	typename T
>
fcppt::variant::recursive<T>::recursive(
	T const &_other
)
:
	rep_(
		recursive::copy(
			_other
		)
	)
{
}

template<
	typename T
>
fcppt::variant::recursive<T>::recursive(
	recursive const &_other
)
:
	rep_(
		recursive::copy(
			_other.get()
		)
	)
{
}

template<
	typename T
>
fcppt::variant::recursive<T> &
fcppt::variant::recursive<T>::operator =(
	T const &_other
)
{
	*rep_ = _other;

	return *this;
}

template<
	typename T
>
fcppt::variant::recursive<T> &
fcppt::variant::recursive<T>::operator =(
	recursive const &_other
)
{
	*rep_ = _other.get();

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
	recursive &_other
)
{
	std::swap(
		rep_,
		_other.rep_
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
	T const &_other
)
{
	return new T(_other);
}

template<
	typename T
>
void
fcppt::variant::swap(
	recursive<T> &_a,
	recursive<T> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
