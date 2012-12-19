//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REFERENCE_WRAPPER_IMPL_HPP_INCLUDED
#define FCPPT_REFERENCE_WRAPPER_IMPL_HPP_INCLUDED

#include <fcppt/reference_wrapper_decl.hpp>


template<
	typename Type
>
fcppt::reference_wrapper<
	Type
>::reference_wrapper(
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
fcppt::reference_wrapper<
	Type
>::reference_wrapper(
	reference_wrapper const &_other
)
:
	impl_(
		_other.impl_
	)
{
}

template<
	typename Type
>
fcppt::reference_wrapper<
	Type
> &
fcppt::reference_wrapper<
	Type
>::operator=(
	reference_wrapper const &_other
)
{
	impl_ = _other.impl_;

	return *this;
}

template<
	typename Type
>
fcppt::reference_wrapper<
	Type
>::~reference_wrapper()
{
}

template<
	typename Type
>
typename fcppt::reference_wrapper<
	Type
>::type &
fcppt::reference_wrapper<
	Type
>::get() const
{
	return
		*impl_;
}

#endif
