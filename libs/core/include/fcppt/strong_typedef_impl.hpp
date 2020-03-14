//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_IMPL_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/strong_typedef_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	typename Tag
>
fcppt::strong_typedef<
	T,
	Tag
>::strong_typedef(
	T _value
)
:
	value_{
		std::move(
			_value
		)
	}
{
}

template<
	typename T,
	typename Tag
>
fcppt::strong_typedef<
	T,
	Tag
>::strong_typedef(
	fcppt::no_init const &
)
{
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
	return
		this->value_;
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
	return
		this->value_;
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
		this->value_,
		_other.value_
	);
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
