//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HOMOGENOUS_PAIR_IMPL_HPP_INCLUDED
#define FCPPT_HOMOGENOUS_PAIR_IMPL_HPP_INCLUDED

#include <fcppt/homogenous_pair_decl.hpp>
#include <algorithm>

template
<
	typename T
>
fcppt::homogenous_pair<T>::homogenous_pair() 
: 
	first(),
	second() 
{}

template
<
	typename T
>
fcppt::homogenous_pair<T>::homogenous_pair(
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

template
<
	typename T
>
void
fcppt::homogenous_pair<T>::swap(
	homogenous_pair &other_
)
{
	std::swap(
		first,
		other_.first
	);

	std::swap(
		second,
		other_.second
	);
}

template
<
	typename T
>
bool 
fcppt::operator<(
	homogenous_pair<T> const &_a,
	homogenous_pair<T> const &_b
)
{
	if (_a.first < _b.first)
		return true;
	if (_b.first < _a.first)
		return false;
	return _a.second < _b.second;
}

template
<
	typename T
>
bool 
fcppt::operator==(
	homogenous_pair<T> const &_a,
	homogenous_pair<T> const &_b
)
{
	return 
		_a.first == _b.first
		&& _a.second == _b.second;
}

template
<
	typename T
>
bool 
fcppt::operator!=(
	homogenous_pair<T> const &_a,
	homogenous_pair<T> const &_b
)
{
	return !(_a == _b);
}

template
<
	typename T
>
void
fcppt::swap(
	homogenous_pair<T> &_a,
	homogenous_pair<T> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
