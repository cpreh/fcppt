//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_OPTIONAL_BASE_IMPL_HPP_INCLUDED
#define FCPPT_DETAIL_OPTIONAL_BASE_IMPL_HPP_INCLUDED

#include <fcppt/null_ptr.hpp>
#include <fcppt/detail/optional_base_decl.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <new>
#include <fcppt/config/external_end.hpp>

template<
	typename T
>
fcppt::detail::optional_base<T>::optional_base()
:
	storage_(),
	data_(
		fcppt::null_ptr()
	)
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

template<
	typename T
>
fcppt::detail::optional_base<T>::optional_base(
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
fcppt::detail::optional_base<T>::optional_base(
	optional_base const &_other
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
fcppt::detail::optional_base<T> &
fcppt::detail::optional_base<T>::operator=(
	optional_base const &_other
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
fcppt::detail::optional_base<T> &
fcppt::detail::optional_base<T>::operator=(
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
fcppt::detail::optional_base<T>::~optional_base()
{
	this->destroy();
}

template<
	typename T
>
typename fcppt::detail::optional_base<T>::pointer
fcppt::detail::optional_base<T>::data() const
{
	return data_;
}

template<
	typename T
>
void
fcppt::detail::optional_base<T>::do_reset()
{
	this->destroy();

	data_ = fcppt::null_ptr();
}

template<
	typename T
>
typename fcppt::detail::optional_base<T>::pointer
fcppt::detail::optional_base<T>::construct(
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
typename fcppt::detail::optional_base<T>::pointer
fcppt::detail::optional_base<T>::construct(
	optional_base const &_other
)
{
	return
		_other.data_
		?
			new (
				storage_.data()
			)
			T(
				*_other.data()
			)
		:
			static_cast<
				pointer
			>(
				fcppt::null_ptr()
			);
}

template<
	typename T
>
void
fcppt::detail::optional_base<T>::destroy()
{
	if(
		data_
	)
		data_->~T();
}


template<
	typename T
>
fcppt::detail::optional_base<T &>::optional_base()
:
	data_(
		fcppt::null_ptr()
	)
{
}

template<
	typename T
>
fcppt::detail::optional_base<T &>::optional_base(
	const_reference _ref
)
:
	data_(
		&_ref
	)
{
}

template<
	typename T
>
template<
	typename Other
>
fcppt::detail::optional_base<T &>::optional_base(
	Other *const _other
)
:
	data_(
		_other
	)
{
}

template<
	typename T
>
fcppt::detail::optional_base<T &>::optional_base(
	optional_base const &_other
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
fcppt::detail::optional_base<T &> &
fcppt::detail::optional_base<T &>::operator=(
	optional_base const &_other
)
{
	data_ = _other.data_;

	return *this;
}

template<
	typename T
>
template<
	typename Other
>
fcppt::detail::optional_base<T &> &
fcppt::detail::optional_base<T &>::operator=(
	Other *const _other
)
{
	data_ = _other;

	return *this;
}

template<
	typename T
>
fcppt::detail::optional_base<T &> &
fcppt::detail::optional_base<T &>::operator=(
	const_reference _ref
)
{
	data_ = &_ref;

	return *this;
}

template<
	typename T
>
fcppt::detail::optional_base<T &>::~optional_base()
{
}

template<
	typename T
>
typename fcppt::detail::optional_base<T &>::pointer
fcppt::detail::optional_base<T &>::data() const
{
	return data_;
}

template<
	typename T
>
void
fcppt::detail::optional_base<T &>::do_reset()
{
	data_ = fcppt::null_ptr();
}

#endif
