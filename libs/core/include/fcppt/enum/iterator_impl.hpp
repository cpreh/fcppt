//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/enum/iterator_decl.hpp>


template<
	typename Enum
>
fcppt::enum_::iterator<
	Enum
>::iterator()
noexcept
:
	value_{}
{
}

template<
	typename Enum
>
fcppt::enum_::iterator<
	Enum
>::iterator(
	size_type const _value
)
noexcept
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
fcppt::enum_::iterator<
	Enum
>::increment()
noexcept
{
	++value_;
}

template<
	typename Enum
>
bool
fcppt::enum_::iterator<
	Enum
>::equal(
	iterator const _other
) const
noexcept
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
fcppt::enum_::iterator<
	Enum
>::dereference() const
noexcept
{
	return
		fcppt::cast::int_to_enum<
			Enum
		>(
			value_
		);
}

#endif
