//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONAL_IMPL_HPP_INCLUDED

#include <fcppt/empty_optional_tag_fwd.hpp>
#include <fcppt/optional_decl.hpp>
#include <fcppt/detail/optional_base_impl.hpp>


template<
	typename T
>
fcppt::optional<T>::optional()
:
	base()
{
}

template<
	typename T
>
fcppt::optional<T>::optional(
	fcppt::empty_optional_tag const &
)
:
	base()
{
}

template<
	typename T
>
fcppt::optional<T>::optional(
	const_reference _other
)
:
	base(
		_other
	)
{
}

template<
	typename T
>
fcppt::optional<T>::optional(
	optional const &_other
)
:
	base(
		_other
	)
{
}

template<
	typename T
>
fcppt::optional<T> &
fcppt::optional<T>::operator=(
	optional const &_other
)
{
	base::operator=(
		_other
	);

	return *this;
}

template<
	typename T
>
fcppt::optional<T> &
fcppt::optional<T>::operator=(
	const_reference _other
)
{
	base::operator=(
		_other
	);

	return *this;
}

template<
	typename T
>
fcppt::optional<T>::~optional()
{
}

template<
	typename T
>
typename fcppt::optional<T>::reference
fcppt::optional<T>::operator*()
{
	return *this->data();
}

template<
	typename T
>
typename fcppt::optional<T>::const_reference
fcppt::optional<T>::operator*() const
{
	return *this->data();
}

template<
	typename T
>
typename fcppt::optional<T>::pointer
fcppt::optional<T>::operator->()
{
	return this->data();
}

template<
	typename T
>
typename fcppt::optional<T>::const_pointer
fcppt::optional<T>::operator->() const
{
	return this->data();
}

template<
	typename T
>
void
fcppt::optional<T>::reset()
{
	base::do_reset();
}

template<
	typename T
>
bool
fcppt::optional<T>::has_value() const
{
	return this->boolean_test();
}

template<
	typename T
>
bool
fcppt::optional<T>::boolean_test() const
{
	return this->data() != 0;
}

#endif
