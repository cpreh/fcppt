//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REFERENCE_IMPL_HPP_INCLUDED
#define FCPPT_REFERENCE_IMPL_HPP_INCLUDED

#include <fcppt/reference_decl.hpp>


template<
	typename Type
>
fcppt::reference<
	Type
>::reference(
	type &_ref
)
:
	impl_(
		&_ref
	)
{
}

template<
	typename Type
>
fcppt::reference<
	Type
>::reference(
	reference const &_other
)
=
default;

template<
	typename Type
>
fcppt::reference<
	Type
> &
fcppt::reference<
	Type
>::operator=(
	reference const &_other
)
=
default;

template<
	typename Type
>
fcppt::reference<
	Type
>::~reference()
{
}

template<
	typename Type
>
typename fcppt::reference<
	Type
>::type &
fcppt::reference<
	Type
>::get() const
{
	return
		*impl_;
}

#endif
