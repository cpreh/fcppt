//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BIT_MASK_IMPL_HPP_INCLUDED
#define FCPPT_BIT_MASK_IMPL_HPP_INCLUDED

#include <fcppt/bit/mask_decl.hpp>


template<
	typename Type
>
inline
constexpr
fcppt::bit::mask<
	Type
>::mask(
	Type const _value
)
noexcept
:
	value_(
		_value
	)
{
}

template<
	typename Type
>
inline
constexpr
Type
fcppt::bit::mask<
	Type
>::get() const
noexcept
{
	return
		value_;
}

#endif
