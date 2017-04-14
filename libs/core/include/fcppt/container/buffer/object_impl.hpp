//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BUFFER_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BUFFER_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/buffer/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	typename A
>
fcppt::container::buffer::object<
	T,
	A
>::object(
	size_type const _size,
	A _alloc
)
:
	impl_{
		_alloc
		,
		_size
		==
		0u
		?
			nullptr
		:
			_alloc.allocate(
				_size,
				nullptr
			)
		,
		_size
	}
{
}

template<
	typename T,
	typename A
>
fcppt::container::buffer::object<
	T,
	A
>::object(
	object &&_other
)
noexcept
:
	impl_{
		std::move(
			_other.impl_
		)
	}
{
	_other.impl_.first_ =
		nullptr;

	_other.impl_.read_ =
		nullptr;

	_other.impl_.write_ =
		nullptr;
}

template<
	typename T,
	typename A
>
fcppt::container::buffer::object<
	T,
	A
> &
fcppt::container::buffer::object<
	T,
	A
>::operator=(
	object &&_other
)
noexcept
{
	_other.swap(
		*this
	);

	return
		*this;
}

template<
	typename T,
	typename A
>
fcppt::container::buffer::object<
	T,
	A
>::~object()
noexcept
{
	if(
		impl_.first_
		!=
		nullptr
	)
		impl_.alloc_.deallocate(
			impl_.first_,
			this->write_size()
		);
}

template<
	typename T,
	typename A
>
typename
fcppt::container::buffer::object<
	T,
	A
>::const_iterator
fcppt::container::buffer::object<
	T,
	A
>::begin() const
noexcept
{
	return
		this->read_data();
}

template<
	typename T,
	typename A
>
typename
fcppt::container::buffer::object<
	T,
	A
>::const_iterator
fcppt::container::buffer::object<
	T,
	A
>::end() const
noexcept
{
	return
		this->read_data_end();
}

template<
	typename T,
	typename A
>
typename
fcppt::container::buffer::object<
	T,
	A
>::const_reference
fcppt::container::buffer::object<
	T,
	A
>::operator[](
	size_type const _index
) const
noexcept
{
	return
		*(
			this->begin()
			+
			_index
		);
}

template<
	typename T,
	typename A
>
typename
fcppt::container::buffer::object<
	T,
	A
>::const_pointer
fcppt::container::buffer::object<
	T,
	A
>::read_data() const
noexcept
{
	return
		impl_.first_;
}

template<
	typename T,
	typename A
>
typename
fcppt::container::buffer::object<
	T,
	A
>::const_pointer
fcppt::container::buffer::object<
	T,
	A
>::read_data_end() const
noexcept
{
	return
		impl_.read_;
}

template<
	typename T,
	typename A
>
typename
fcppt::container::buffer::object<
	T,
	A
>::pointer
fcppt::container::buffer::object<
	T,
	A
>::write_data()
noexcept
{
	return
		impl_.read_;
}

template<
	typename T,
	typename A
>
typename
fcppt::container::buffer::object<
	T,
	A
>::pointer
fcppt::container::buffer::object<
	T,
	A
>::write_data_end()
noexcept
{
	return
		impl_.write_;
}

template<
	typename T,
	typename A
>
typename
fcppt::container::buffer::object<
	T,
	A
>::size_type
fcppt::container::buffer::object<
	T,
	A
>::read_size() const
noexcept
{
	return
		fcppt::cast::to_unsigned(
			impl_.read_
			-
			impl_.first_
		);
}

template<
	typename T,
	typename A
>
typename
fcppt::container::buffer::object<
	T,
	A
>::size_type
fcppt::container::buffer::object<
	T,
	A
>::write_size() const
noexcept
{
	return
		fcppt::cast::to_unsigned(
			impl_.write_
			-
			impl_.read_
		);
}

template<
	typename T,
	typename A
>
void
fcppt::container::buffer::object<
	T,
	A
>::written(
	size_type const _sz
)
noexcept
{
	impl_.read_ +=
		_sz;
}

template<
	typename T,
	typename A
>
void
fcppt::container::buffer::object<
	T,
	A
>::swap(
	object &_other
)
noexcept
{
	std::swap(
		impl_,
		_other.impl_
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::buffer::object<
	T,
	A
>::release_internal()
{
	impl_.first_ =
		nullptr;

	impl_.read_ =
		nullptr;

	impl_.write_ =
		nullptr;
}

template<
	typename T,
	typename A
>
typename
fcppt::container::buffer::object<
	T,
	A
>::allocator_type
fcppt::container::buffer::object<
	T,
	A
>::get_allocator() const
{
	return
		impl_.alloc_;
}

template<
	typename T,
	typename A
>
fcppt::container::buffer::object<
	T,
	A
>::impl::impl(
	A const &_alloc,
	pointer const _first,
	size_type const _size
)
:
	alloc_{
		_alloc
	},
	first_{
		_first
	},
	read_{
		first_
	},
	write_{
		_first
		==
		nullptr
		?
			_first
		:
			_first
			+
			_size
	}
{
}

template<
	typename T,
	typename A
>
fcppt::container::buffer::object<
	T,
	A
>::impl::impl(
	impl &&
)
noexcept
= default;

template<
	typename T,
	typename A
>
typename
fcppt::container::buffer::object<
	T,
	A
>::impl &
fcppt::container::buffer::object<
	T,
	A
>::impl::operator=(
	impl &&
)
noexcept
= default;

template<
	typename T,
	typename A
>
fcppt::container::buffer::object<
	T,
	A
>::impl::~impl()
noexcept
{
}

template<
	typename T,
	typename A
>
void
fcppt::container::buffer::swap(
	fcppt::container::buffer::object<
		T,
		A
	> &_x,
	fcppt::container::buffer::object<
		T,
		A
	> &_y
)
noexcept
{
	_x.swap(
		_y
	);
}

#endif
