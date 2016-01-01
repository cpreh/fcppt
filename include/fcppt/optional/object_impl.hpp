//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONAL_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/optional/object_decl.hpp>
#include <fcppt/optional/detail/enable_ref_conv.hpp>
#include <fcppt/optional/detail/enable_value_conv.hpp>
#include <fcppt/config/external_begin.hpp>
#include <new>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T
>
fcppt::optional::object<
	T
>::object()
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
fcppt::optional::object<
	T
>::object(
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
fcppt::optional::object<
	T
>::object(
	T &&_other
)
:
	storage_(),
	initialized_(
		true
	)
{
	this->move_from(
		std::move(
			_other
		)
	);
}

template<
	typename T
>
template<
	typename Other
>
fcppt::optional::object<
	T
>::object(
	fcppt::optional::object<
		Other
	> const &_other,
	fcppt::optional::detail::enable_value_conv<
		T,
		Other,
		void
	> const *
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
fcppt::optional::object<
	T
>::object(
	object const &_other
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
fcppt::optional::object<
	T
>::object(
	object &&_other
)
noexcept(
	std::is_nothrow_move_constructible<
		T
	>::value
)
:
	storage_(),
	initialized_(
		_other.has_value()
	)
{
	this->move_from(
		std::move(
			_other
		)
	);
}

template<
	typename T
>
fcppt::optional::object<
	T
> &
fcppt::optional::object<
	T
>::operator=(
	object const &_other
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
fcppt::optional::object<
	T
> &
fcppt::optional::object<
	T
>::operator=(
	object &&_other
)
noexcept(
	std::is_nothrow_move_constructible<
		T
	>::value
	&&
	std::is_nothrow_move_assignable<
		T
	>::value
)
{
	return
		this->move_assign(
			std::move(
				_other
			)
		);
}

template<
	typename T
>
template<
	typename Other
>
fcppt::optional::detail::enable_value_conv<
	T,
	Other,
	fcppt::optional::object<
		T
	> &
>
fcppt::optional::object<
	T
>::operator=(
	fcppt::optional::object<
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
fcppt::optional::object<
	T
>::~object()
{
	this->destroy();
}

template<
	typename T
>
typename
fcppt::optional::object<
	T
>::reference
fcppt::optional::object<
	T
>::get_unsafe()
{
	return
		*this->data();
}

template<
	typename T
>
typename
fcppt::optional::object<
	T
>::const_reference
fcppt::optional::object<
	T
>::get_unsafe() const
{
	return
		*this->data();
}

template<
	typename T
>
bool
fcppt::optional::object<
	T
>::has_value() const
{
	return
		initialized_;
}

template<
	typename T
>
typename
fcppt::optional::object<
	T
>::pointer
fcppt::optional::object<
	T
>::data()
{
	return
		fcppt::cast::from_void_ptr<
			T *
		>(
			this->raw_data()
		);
}

template<
	typename T
>
typename
fcppt::optional::object<
	T
>::const_pointer
fcppt::optional::object<
	T
>::data() const
{
	return
		fcppt::cast::from_void_ptr<
			T const *
		>(
			this->raw_data()
		);
}

template<
	typename T
>
void *
fcppt::optional::object<
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
fcppt::optional::object<
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
fcppt::optional::object<
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
fcppt::optional::object<
	T
>::construct(
	fcppt::optional::object<
		Other
	> const &_other
)
{
	if(
		_other.has_value()
	)
		this->construct(
			_other.get_unsafe()
		);
}

template<
	typename T
>
void
fcppt::optional::object<
	T
>::move_from(
	T &&_other
)
{
	new (
		this->raw_data()
	)
	T(
		std::move(
			_other
		)
	);
}

template<
	typename T
>
void
fcppt::optional::object<
	T
>::move_from(
	object &&_other
)
{
	if(
		_other.has_value()
	)
	{
		this->move_from(
			std::move(
				_other.get_unsafe()
			)
		);

		_other.reset();
	}
}

template<
	typename T
>
void
fcppt::optional::object<
	T
>::reset()
{
	this->destroy();

	initialized_ = false;
}

template<
	typename T
>
fcppt::optional::object<
	T
> &
fcppt::optional::object<
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
fcppt::optional::object<
	T
> &
fcppt::optional::object<
	T
>::assign(
	fcppt::optional::object<
		Other
	> const &_other
)
{
	if(
		this->has_value()
		&&
		_other.has_value()
	)
		*this->data() = _other.get_unsafe();
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
fcppt::optional::object<
	T
> &
fcppt::optional::object<
	T
>::move_assign(
	T && _other
)
{
	if(
		this->has_value()
	)
		*this->data() =
			std::move(
				_other
			);
	else
	{
		this->move_from(
			std::move(
				_other
			)
		);

		initialized_ = true;
	}

	return *this;
}

template<
	typename T
>
fcppt::optional::object<
	T
> &
fcppt::optional::object<
	T
>::move_assign(
	object &&_other
)
{
	if(
		this->has_value()
		&&
		_other.has_value()
	)
	{
		*this->data() =
			std::move(
				_other.get_unsafe()
			);

		_other.reset();
	}
	else
	{
		this->destroy();

		initialized_ = _other.has_value();

		this->move_from(
			std::move(
				_other
			)
		);
	}

	return *this;
}

template<
	typename T
>
void
fcppt::optional::object<
	T
>::destroy()
{
	if(
		this->has_value()
	)
		this->data()->~T();
}

template<
	typename T
>
fcppt::optional::object<
	T &
>::object()
:
	data_(
		nullptr
	)
{
}

template<
	typename T
>
fcppt::optional::object<
	T &
>::object(
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
fcppt::optional::object<
	T &
>::object(
	fcppt::optional::object<
		Other &
	> const &_other,
	fcppt::optional::detail::enable_ref_conv<
		T,
		Other
	> *
)
:
	data_(
		_other.has_value()
		?
			&_other.get_unsafe()
		:
			nullptr
	)
{
}

template<
	typename T
>
fcppt::optional::object<
	T &
>::object(
	object const &_other
)
noexcept
:
	data_(
		_other.data_
	)
{
}

template<
	typename T
>
fcppt::optional::object<
	T &
>::object(
	object &&_other
)
noexcept
:
	data_(
		_other.data_
	)
{
	_other.data_ =
		nullptr;
}

template<
	typename T
>
fcppt::optional::object<
	T &
> &
fcppt::optional::object<
	T &
>::operator=(
	object const &_other
)
noexcept
{
	data_ =
		_other.data_;

	return
		*this;
}

template<
	typename T
>
fcppt::optional::object<
	T &
> &
fcppt::optional::object<
	T &
>::operator=(
	object &&_other
)
noexcept
{
	data_ =
		_other.data_;

	_other.data_ =
		nullptr;

	return
		*this;
}

template<
	typename T
>
fcppt::optional::object<
	T &
>::~object()
{
}

template<
	typename T
>
typename
fcppt::optional::object<
	T &
>::reference
fcppt::optional::object<
	T &
>::get_unsafe() const
{
	return
		*data_;
}

template<
	typename T
>
typename
fcppt::optional::object<
	T &
>::pointer
fcppt::optional::object<
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
fcppt::optional::object<
	T &
>::has_value() const
{
	return
		data_
		!=
		nullptr;
}

#endif
