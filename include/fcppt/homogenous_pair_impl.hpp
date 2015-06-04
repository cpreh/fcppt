//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HOMOGENOUS_PAIR_IMPL_HPP_INCLUDED
#define FCPPT_HOMOGENOUS_PAIR_IMPL_HPP_INCLUDED

#include <fcppt/homogenous_pair_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T
>
fcppt::homogenous_pair<
	T
>::homogenous_pair(
	value_type const &_first,
	value_type const &_second
)
:
	first(
		_first
	),
	second(
		_second
	)
{
}

template<
	typename T
>
void
fcppt::homogenous_pair<
	T
>::swap(
	homogenous_pair &_other
)
{
	using std::swap;

	swap(
		first,
		_other.first
	);

	swap(
		second,
		_other.second
	);
}

template<
	typename T
>
void
fcppt::swap(
	fcppt::homogenous_pair<
		T
	> &_a,
	fcppt::homogenous_pair<
		T
	> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
