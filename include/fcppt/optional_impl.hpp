//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONAL_IMPL_HPP_INCLUDED

#include <fcppt/optional_decl.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <new>
#include <fcppt/config/external_end.hpp>

template<
	typename T
>
fcppt::optional<T>::optional()
:
	storage_(),
	data_(0)
{
}

template<
	typename T
>
fcppt::optional<T>::optional(
	empty_optional_tag const &
)
:
	storage_(),
	data_(0)
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

template<
	typename T
>
fcppt::optional<T>::optional(
	const_reference _other
)
:
	storage_(),
	data_(
		this->construct(
			_other
		)
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
	storage_(),
	data_(
		this->construct(
			_other
		)
	)
{
}

FCPPT_PP_POP_WARNING

template<
	typename T
>
fcppt::optional<T> &
fcppt::optional<T>::operator=(
	optional const &_other
)
{
	this->destroy();

	data_ =
		this->construct(
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
	this->destroy();

	data_ =
		this->construct(
			_other
		);

	return *this;
}

template<
	typename T
>
fcppt::optional<T>::~optional()
{
	this->destroy();
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
	this->destroy();

	data_ = 0;
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
	return data_ != 0;
}

template<
	typename T
>
typename fcppt::optional<T>::pointer
fcppt::optional<T>::construct(
	const_reference _other
)
{
	return
		new (
			storage_.data()
		)
		T(
			_other
		);
}

template<
	typename T
>
typename fcppt::optional<T>::pointer
fcppt::optional<T>::construct(
	optional const &_other
)
{
	return
		_other.data_
		?
			new (
				storage_.data()
			)
			T(
				*_other
			)
		:
			static_cast<
				pointer
			>(
				0
			);
}

template<
	typename T
>
void
fcppt::optional<T>::destroy()
{
	if(
		data_
	)
		data_->~T();
}

#endif
