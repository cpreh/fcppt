//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BUFFER_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BUFFER_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/buffer/object_decl.hpp>
#include <fcppt/container/raw_vector/rep_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <memory>
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
	size_type const _size
)
:
	object(
		_size,
		A{}
	)
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
	size_type const _size,
	A _alloc
)
:
	impl_{
		_alloc,
		_alloc.allocate(
			_size,
			nullptr
		),
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
	_other.release_internal();
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
	impl_.deallocate();
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
		this->impl_.first_;
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
		this->impl_.read_end_;
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
		this->impl_.read_end_;
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
		this->impl_.write_end_;
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
			this->impl_.read_end_
			-
			this->impl_.first_
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
			this->impl_.write_end_
			-
			this->impl_.read_end_
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
	this->impl_.read_end_ +=
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
>::resize_write_area(
	size_type const _sz
)
{
	if(
		fcppt::cast::to_unsigned(
			this->impl_.cap_
			-
			this->impl_.read_end_
		)
		>=
		_sz
	)
	{
		this->impl_.write_end_ =
			this->impl_.read_end_
			+
			fcppt::cast::to_signed(
				_sz
			);

		return;
	}

	size_type const new_size{
		std::max(
			fcppt::cast::size<
				size_type
			>(
				fcppt::cast::to_unsigned(
					this->impl_.cap_
					-
					this->impl_.first_
				)
				*
				2U
			),
			_sz
			+
			this->read_size()
		)
	};

	impl new_impl{
		this->impl_.alloc_,
		// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
		this->impl_.alloc_.allocate(
			new_size
		),
		new_size
	};

	std::uninitialized_copy(
		this->read_data(),
		this->read_data_end(),
		new_impl.first_
	);

	new_impl.read_end_ =
		new_impl.first_
		+
		fcppt::cast::to_signed(
			this->read_size()
		);

	new_impl.write_end_ =
		new_impl.read_end_
		+
		fcppt::cast::to_signed(
			_sz
		);

	this->impl_.deallocate();

	this->impl_ =
		std::move(
			new_impl
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
>::swap(
	object &_other
)
noexcept
{
	std::swap(
		this->impl_,
		_other.impl_
	);
}


template<
	typename T,
	typename A
>
fcppt::container::raw_vector::rep<
	A
>
fcppt::container::buffer::object<
	T,
	A
>::release()
noexcept
{
	fcppt::container::raw_vector::rep<
		A
	> const result{
		this->get_allocator(),
		this->impl_.first_,
		this->impl_.read_end_,
		this->impl_.cap_
	};

	this->release_internal();

	return
		result;
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
noexcept
{
	this->impl_.first_ =
		nullptr;

	this->impl_.read_end_ =
		nullptr;

	this->impl_.write_end_ =
		nullptr;

	this->impl_.cap_ =
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
		this->impl_.alloc_;
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
	read_end_{
		first_
	},
	write_end_{
		_first
		==
		nullptr
		?
			_first
		:
			_first
			+
			_size
	},
	cap_{
		write_end_
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
=
default;

template<
	typename T,
	typename A
>
void
fcppt::container::buffer::object<
	T,
	A
>::impl::deallocate()
noexcept
{
	if(
		this->first_
		!=
		nullptr
	)
	{
		this->alloc_.deallocate(
			this->first_,
			fcppt::cast::to_unsigned(
				this->cap_
				-
				this->first_
			)
		);
	}
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
