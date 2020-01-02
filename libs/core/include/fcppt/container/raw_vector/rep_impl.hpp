//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_RAW_VECTOR_REP_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_REP_IMPL_HPP_INCLUDED

#include <fcppt/container/raw_vector/rep_decl.hpp>


template<
	typename A
>
fcppt::container::raw_vector::rep<
	A
>::rep(
	A const &_alloc,
	pointer const _first,
	pointer const _last,
	pointer const _cap
)
noexcept
:
	alloc_{
		_alloc
	},
	first_{
		_first
	},
	last_{
		_last
	},
	cap_{
		_cap
	}
{
}

template<
	typename A
>
fcppt::container::raw_vector::rep<
	A
>::rep(
	rep const &
)
noexcept
=
default;

template<
	typename A
>
fcppt::container::raw_vector::rep<
	A
> &
fcppt::container::raw_vector::rep<
	A
>::operator=(
	rep const &
)
noexcept
=
default;

template<
	typename A
>
fcppt::container::raw_vector::rep<
	A
>::~rep()
noexcept
{
}

template<
	typename A
>
A const &
fcppt::container::raw_vector::rep<
	A
>::alloc() const
noexcept
{
	return
		alloc_;
}

template<
	typename A
>
typename
fcppt::container::raw_vector::rep<
	A
>::pointer
fcppt::container::raw_vector::rep<
	A
>::first() const
noexcept
{
	return
		first_;
}

template<
	typename A
>
typename
fcppt::container::raw_vector::rep<
	A
>::pointer
fcppt::container::raw_vector::rep<
	A
>::last() const
noexcept
{
	return
		last_;
}

template<
	typename A
>
typename
fcppt::container::raw_vector::rep<
	A
>::pointer
fcppt::container::raw_vector::rep<
	A
>::cap() const
noexcept
{
	return
		cap_;
}


#endif
