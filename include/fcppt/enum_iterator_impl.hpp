//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/enum_iterator_decl.hpp>
#include <fcppt/cast/int_to_enum.hpp>


template<
	typename Enum
>
fcppt::enum_iterator<
	Enum
>::enum_iterator()
:
	value_{}
{
}

template<
	typename Enum
>
fcppt::enum_iterator<
	Enum
>::enum_iterator(
	size_type const _value
)
:
	value_(
		_value
	)
{
}

template<
	typename Enum
>
void
fcppt::enum_iterator<
	Enum
>::increment()
{
	++value_;
}

template<
	typename Enum
>
bool
fcppt::enum_iterator<
	Enum
>::equal(
	enum_iterator const _other
) const
{
	return
		value_
		==
		_other.value_;
}

template<
	typename Enum
>
Enum
fcppt::enum_iterator<
	Enum
>::dereference() const
{
	return
		fcppt::cast::int_to_enum<
			Enum
		>(
			value_
		);
}

#endif
