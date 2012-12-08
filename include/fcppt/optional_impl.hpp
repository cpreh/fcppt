//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONAL_IMPL_HPP_INCLUDED

#include <fcppt/optional_decl.hpp>
#include <fcppt/detail/enable_optional_ref_conv.hpp>
#include <fcppt/detail/enable_optional_value_conv.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


/// \cond FCPPT_DOXYGEN_DEBUG

template<
	typename T
>
fcppt::optional<T>::optional()
:
	storage_(),
	data_(
		nullptr
	)
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
template<
	typename Other
>
fcppt::optional<T>::optional(
	optional<
		Other
	> const &_other,
	typename fcppt::detail::enable_optional_value_conv<
		T,
		Other,
		void
	>::type const *
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
	return
		this->assign(
			_other
		);
}

template<
	typename T
>
fcppt::optional<T> &
fcppt::optional<T>::operator=(
	const_reference _other
)
{
	return
		this->assign(
			_other
		);
}

template<
	typename T
>
template<
	typename Other
>
typename fcppt::detail::enable_optional_value_conv<
	T,
	Other,
	fcppt::optional<T> &
>::type
fcppt::optional<T>::operator=(
	optional<
		Other
	> const &_other
)
{
	return
		this->assign(
			_other
		);
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

	data_ = nullptr;
}

template<
	typename T
>
bool
fcppt::optional<T>::has_value() const
{
	return
		data_ != nullptr;
}

template<
	typename T
>
fcppt::optional<T>::operator bool() const
{
	return
		this->has_value();
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
template<
	typename Other
>
typename fcppt::optional<T>::pointer
fcppt::optional<T>::construct(
	optional<
		Other
	> const &_other
)
{
	return
		_other.has_value()
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
				nullptr
			);
}

template<
	typename T
>
fcppt::optional<T> &
fcppt::optional<T>::assign(
	const_reference _other
)
{
	if(
		this->has_value()
	)
		*data_ = _other;
	else
		this->copy_from_other(
			_other
		);

	return *this;
}

template<
	typename T
>
template<
	typename Other
>
fcppt::optional<T> &
fcppt::optional<T>::assign(
	optional<
		Other
	> const &_other
)
{
	if(
		this->has_value()
		&& _other.has_value()
	)
		*data_ = *_other;
	else
		this->copy_from_other(
			_other
		);

	return *this;
}

template<
	typename T
>
template<
	typename Other
>
void
fcppt::optional<T>::copy_from_other(
	Other const &_other
)
{
	this->destroy();

	data_ =
		this->construct(
			_other
		);
}

template<
	typename T
>
void
fcppt::optional<T>::destroy()
{
	if(
		data_ != nullptr
	)
		data_->~T();
}


template<
	typename T
>
fcppt::optional<T &>::optional()
:
	data_(
		nullptr
	)
{
}

template<
	typename T
>
fcppt::optional<T &>::optional(
	reference _other
)
:
	data_(
		&_other
	)
{
}

template<
	typename T
>
template<
	typename Other
>
fcppt::optional<T &>::optional(
	optional<
		Other &
	> const &_other,
	typename detail::enable_optional_ref_conv<
		T,
		Other
	>::type *
)
:
	data_(
		_other.has_value()
		?
			&*_other
		:
			nullptr
	)
{
}

template<
	typename T
>
fcppt::optional<T &>::optional(
	optional const &_other
)
:
	data_(
		_other.data_
	)
{
}

template<
	typename T
>
fcppt::optional<T &> &
fcppt::optional<T &>::operator=(
	optional const &_other
)
{
	data_ = _other.data_;

	return *this;
}

template<
	typename T
>
fcppt::optional<T &>::~optional()
{
}

template<
	typename T
>
typename fcppt::optional<T &>::reference
fcppt::optional<T &>::operator*() const
{
	return *data_;
}

template<
	typename T
>
typename fcppt::optional<T &>::pointer
fcppt::optional<T &>::operator->() const
{
	return data_;
}

template<
	typename T
>
bool
fcppt::optional<T &>::has_value() const
{
	return
		data_ != nullptr;
}

template<
	typename T
>
fcppt::optional<T &>::operator bool() const
{
	return
		this->has_value();
}

/// \endcond FCPPT_DOXYGEN_DEBUG

#endif
