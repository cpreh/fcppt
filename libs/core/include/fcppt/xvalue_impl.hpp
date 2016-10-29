//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_XVALUE_IMPL_HPP_INCLUDED
#define FCPPT_XVALUE_IMPL_HPP_INCLUDED

#include <fcppt/xvalue_decl.hpp>


template<
	typename Type
>
inline
fcppt::xvalue<
	Type
>::xvalue(
	type &_ref
)
noexcept
:
	impl_(
		&_ref
	)
{
}

template<
	typename Type
>
inline
typename
fcppt::xvalue<
	Type
>::type &
fcppt::xvalue<
	Type
>::get() const
noexcept
{
	return
		*impl_;
}

#endif
