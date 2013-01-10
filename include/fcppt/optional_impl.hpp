//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONAL_IMPL_HPP_INCLUDED

#include <fcppt/optional_decl.hpp>
#include <fcppt/detail/enable_optional_ref_conv.hpp>
#include <fcppt/detail/enable_optional_value_conv.hpp>
#include <fcppt/config/external_begin.hpp>
#include <new>
#include <fcppt/config/external_end.hpp>


/// \cond FCPPT_DOXYGEN_DEBUG

template<
	typename T
>
fcppt::optional<
	T
>::optional()
:
	storage_(),
	initialized_(
		false
	)
{
}

template<
	typename T
>
fcppt::optional<
	T
>::optional(
	const_reference _other
)
:
	storage_(),
	initialized_(
		true
	)
{
	this->construct(
		_other
	);
}

template<
	typename T
>
template<
	typename Other
>
fcppt::optional<
	T
>::optional(
	fcppt::optional<
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
	initialized_(
		_other.has_value()
	)
{
	this->construct(
		_other
	);
}

template<
	typename T
>
fcppt::optional<
	T
>::optional(
	optional const &_other
)
:
	storage_(),
	initialized_(
		_other.has_value()
	)
{
	this->construct(
		_other
	);
}

template<
	typename T
>
fcppt::optional<
	T
> &
fcppt::optional<
	T
>::operator=(
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
fcppt::optional<
	T
> &
fcppt::optional<
	T
>::operator=(
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
	fcppt::optional<
		T
	> &
>::type
fcppt::optional<
	T
>::operator=(
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
fcppt::optional<
	T
>::~optional()
{
	this->destroy();
}

template<
	typename T
>
typename fcppt::optional<
	T
>::reference
fcppt::optional<
	T
>::operator*()
{
	return
		*this->data();
}

template<
	typename T
>
typename fcppt::optional<
	T
>::const_reference
fcppt::optional<
	T
>::operator*() const
{
	return
		*this->data();
}

template<
	typename T
>
typename fcppt::optional<
	T
>::pointer
fcppt::optional<
	T
>::operator->()
{
	return
		this->data();
}

template<
	typename T
>
typename fcppt::optional<
	T
>::const_pointer
fcppt::optional<
	T
>::operator->() const
{
	return
		this->data();
}

template<
	typename T
>
void
fcppt::optional<
	T
>::reset()
{
	this->destroy();

	initialized_ = false;
}

template<
	typename T
>
bool
fcppt::optional<
	T
>::has_value() const
{
	return
		initialized_;
}

template<
	typename T
>
fcppt::optional<
	T
>::operator bool() const
{
	return
		this->has_value();
}

template<
	typename T
>
typename fcppt::optional<
	T
>::pointer
fcppt::optional<
	T
>::data()
{
	return
		static_cast<
			T *
		>(
			this->raw_data()
		);
}

template<
	typename T
>
typename fcppt::optional<
	T
>::const_pointer
fcppt::optional<
	T
>::data() const
{
	return
		static_cast<
			T const *
		>(
			this->raw_data()
		);
}

template<
	typename T
>
void *
fcppt::optional<
	T
>::raw_data()
{
	return
		&storage_;
}

template<
	typename T
>
void const *
fcppt::optional<
	T
>::raw_data() const
{
	return
		&storage_;
}

template<
	typename T
>
void
fcppt::optional<
	T
>::construct(
	const_reference _other
)
{
	new (
		this->raw_data()
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
void
fcppt::optional<
	T
>::construct(
	fcppt::optional<
		Other
	> const &_other
)
{
	if(
		_other.has_value()
	)
		this->construct(
			*_other
		);
}

template<
	typename T
>
fcppt::optional<
	T
> &
fcppt::optional<
	T
>::assign(
	const_reference _other
)
{
	if(
		this->has_value()
	)
		*this->data() = _other;
	else
	{
		this->destroy_unchecked();

		this->construct(
			_other
		);

		initialized_ = true;
	}

	return *this;
}

template<
	typename T
>
template<
	typename Other
>
fcppt::optional<
	T
> &
fcppt::optional<
	T
>::assign(
	fcppt::optional<
		Other
	> const &_other
)
{
	if(
		this->has_value()
		&& _other.has_value()
	)
		*this->data() = *_other;
	else
	{
		this->destroy();

		this->construct(
			_other
		);

		initialized_ = _other.has_value();
	}

	return *this;
}

template<
	typename T
>
void
fcppt::optional<
	T
>::destroy()
{
	if(
		this->has_value()
	)
		this->destroy_unchecked();
}

template<
	typename T
>
void
fcppt::optional<
	T
>::destroy_unchecked()
{
	this->data()->~T();
}

template<
	typename T
>
fcppt::optional<
	T &
>::optional()
:
	data_(
		nullptr
	)
{
}

template<
	typename T
>
fcppt::optional<
	T &
>::optional(
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
fcppt::optional<
	T &
>::optional(
	fcppt::optional<
		Other &
	> const &_other,
	typename fcppt::detail::enable_optional_ref_conv<
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
fcppt::optional<
	T &
>::optional(
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
fcppt::optional<
	T &
> &
fcppt::optional<
	T &
>::operator=(
	optional const &_other
)
{
	data_ = _other.data_;

	return *this;
}

template<
	typename T
>
fcppt::optional<
	T &
>::~optional()
{
}

template<
	typename T
>
typename fcppt::optional<
	T &
>::reference
fcppt::optional<
	T &
>::operator*() const
{
	return
		*data_;
}

template<
	typename T
>
typename fcppt::optional<
	T &
>::pointer
fcppt::optional<
	T &
>::operator->() const
{
	return
		data_;
}

template<
	typename T
>
typename fcppt::optional<
	T &
>::pointer
fcppt::optional<
	T &
>::data() const
{
	return
		data_;
}

template<
	typename T
>
bool
fcppt::optional<
	T &
>::has_value() const
{
	return
		data_ != nullptr;
}

template<
	typename T
>
fcppt::optional<
	T &
>::operator bool() const
{
	return
		this->has_value();
}

/// \endcond FCPPT_DOXYGEN_DEBUG

#endif
