//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONAL_IMPL_HPP_INCLUDED

#include <fcppt/optional_decl.hpp>
#include <new>

template<
	typename T
>
fcppt::optional<T>::optional()
:
	storage_(),
	data_(0)
{}

template<
	typename T
>
fcppt::optional<T>::optional(
	empty_optional_tag const &
)
:
	storage_(),
	data_(0)
{}

template<
	typename T
>
fcppt::optional<T>::optional(
	const_reference ref
)
:
	storage_(),
	data_(
		optional::construct(
			ref
		)
	)
{}

template<
	typename T
>
fcppt::optional<T>::optional(
	optional const &o
)
:
	storage_(),
	data_(
		optional::construct(
			o
		)
	)
{}

template<
	typename T
>
fcppt::optional<T> &
fcppt::optional<T>::operator=(
	optional const &o
)
{
	optional::destroy();
	data_ = optional::construct(o);
	return *this;
}

template<
	typename T
>
fcppt::optional<T> &
fcppt::optional<T>::operator=(
	const_reference r
)
{
	optional::destroy();
	data_ = optional::construct(r);
	return *this;
}

template<
	typename T
>
fcppt::optional<T>::~optional()
{
	optional::destroy();
}

template<
	typename T
>
typename fcppt::optional<T>::reference
fcppt::optional<T>::operator*()
{
	return *data_;
}

template<
	typename T
>
typename fcppt::optional<T>::const_reference
fcppt::optional<T>::operator*() const
{
	return *data_;
}

template<
	typename T
>
typename fcppt::optional<T>::pointer
fcppt::optional<T>::operator->()
{
	return data_;
}

template<
	typename T
>
typename fcppt::optional<T>::const_pointer
fcppt::optional<T>::operator->() const
{
	return data_;
}

template<
	typename T
>
void
fcppt::optional<T>::reset()
{
	destroy();
	data_ = 0;
}

template<
	typename T
>
bool
fcppt::optional<T>::has_value() const
{
	return boolean_test();
}

template<
	typename T
>
bool
fcppt::optional<T>::boolean_test() const
{
	return data_ != 0;
}

template<
	typename T
>
typename fcppt::optional<T>::pointer
fcppt::optional<T>::construct(
	const_reference r
)
{
	return data_ = new (storage_.data()) T(r);
}

template<
	typename T
>
typename fcppt::optional<T>::pointer
fcppt::optional<T>::construct(
	optional const &o
)
{
	return o.data_
		? new (storage_.data()) T(*o)
		: static_cast<pointer>(0);
}

template<
	typename T
>
void
fcppt::optional<T>::destroy()
{
	if(data_)
		data_->~T();
}

#endif
