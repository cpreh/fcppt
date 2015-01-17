//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INT_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_INT_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/int_iterator_decl.hpp>


template<
	typename Int
>
fcppt::int_iterator<
	Int
>::int_iterator()
:
	value_{}
{
}

template<
	typename Int
>
fcppt::int_iterator<
	Int
>::int_iterator(
	Int const _value
)
:
	value_(
		_value
	)
{
}

template<
	typename Int
>
void
fcppt::int_iterator<
	Int
>::increment()
{
	++value_;
}

template<
	typename Int
>
bool
fcppt::int_iterator<
	Int
>::equal(
	int_iterator const _other
) const
{
	return
		value_
		==
		_other.value_;
}

template<
	typename Int
>
Int
fcppt::int_iterator<
	Int
>::dereference() const
{
	return
		value_;
}

#endif
