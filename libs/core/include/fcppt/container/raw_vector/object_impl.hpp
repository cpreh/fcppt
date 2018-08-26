//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_RAW_VECTOR_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/raw_vector/object_decl.hpp>
#include <fcppt/container/raw_vector/rep_impl.hpp>
#include <fcppt/type_traits/is_iterator_of_category.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <memory>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::iterator
fcppt::container::raw_vector::object<
	T,
	A
>::begin()
noexcept
{
	return
		this->data();
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::const_iterator
fcppt::container::raw_vector::object<
	T,
	A
>::begin() const
noexcept
{
	return
		this->data();
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::iterator
fcppt::container::raw_vector::object<
	T,
	A
>::end()
noexcept
{
	return
		this->data_end();
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::const_iterator
fcppt::container::raw_vector::object<
	T,
	A
>::end() const
noexcept
{
	return
		this->data_end();
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::reference
fcppt::container::raw_vector::object<
	T,
	A
>::operator[](
	size_type const _index
)
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
fcppt::container::raw_vector::object<
	T,
	A
>::const_reference
fcppt::container::raw_vector::object<
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
fcppt::container::raw_vector::object<
	T,
	A
>::reference
fcppt::container::raw_vector::object<
	T,
	A
>::front()
noexcept
{
	return
		*this->begin();
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::const_reference
fcppt::container::raw_vector::object<
	T,
	A
>::front() const
noexcept
{
	return
		*this->begin();
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::reference
fcppt::container::raw_vector::object<
	T,
	A
>::back()
noexcept
{
	return
		*(
			std::prev(
				this->end()
			)
		);
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::const_reference
fcppt::container::raw_vector::object<
	T,
	A
>::back() const
noexcept
{
	return
		*(
			std::prev(
				this->end()
			)
		);
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::pointer
fcppt::container::raw_vector::object<
	T,
	A
>::data()
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
fcppt::container::raw_vector::object<
	T,
	A
>::const_pointer
fcppt::container::raw_vector::object<
	T,
	A
>::data() const
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
fcppt::container::raw_vector::object<
	T,
	A
>::pointer
fcppt::container::raw_vector::object<
	T,
	A
>::data_end()
noexcept
{
	return
		impl_.last_;
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::const_pointer
fcppt::container::raw_vector::object<
	T,
	A
>::data_end() const
noexcept
{
	return
		impl_.last_;
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector::object<
	T,
	A
>::object(
	A const &_alloc
)
:
	impl_{
		_alloc
	}
{
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector::object<
	T,
	A
>::object(
	size_type const _sz,
	T const &_value,
	A const &_alloc
)
:
	impl_{
		_alloc
	}
{
	this->insert(
		this->end(),
		_sz,
		_value
	);
}

template<
	typename T,
	typename A
>
template<
	typename In
>
fcppt::container::raw_vector::object<
	T,
	A
>::object(
	In const _begin,
	In const _end,
	A const &_alloc
)
:
	impl_(
		_alloc
	)
{
	this->insert(
		this->end(),
		_begin,
		_end
	);
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector::object<
	T,
	A
>::object(
	fcppt::container::raw_vector::rep<
		A
	> const &_rep
)
noexcept
:
	impl_{
		_rep
	}
{
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector::object<
	T,
	A
>::object(
	std::initializer_list<
		T
	> const _inits,
	A const &_alloc
)
:
	impl_(
		_alloc
	)
{
	this->insert(
		this->end(),
		_inits.begin(),
		_inits.end()
	);
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector::object<
	T,
	A
>::object(
	object &&_other
)
noexcept
:
	impl_(
		std::move(
			_other.impl_
		)
	)
{
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector::object<
	T,
	A
>::~object()
noexcept
{
	this->deallocate();
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector::object<
	T,
	A
> &
fcppt::container::raw_vector::object<
	T,
	A
>::operator=(
	object &&_other
)
noexcept
{
	this->swap(
		_other
	);

	return
		*this;
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::push_back(
	T const &_value
)
{
	this->insert(
		this->end(),
		_value
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::pop_back()
noexcept
{
	this->erase(
		std::prev(
			this->end()
		)
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::clear()
noexcept
{
	this->erase(
		this->begin(),
		this->end()
	);
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::size_type
fcppt::container::raw_vector::object<
	T,
	A
>::size() const
noexcept
{
	return
		fcppt::cast::to_unsigned(
			std::distance(
				impl_.first_,
				impl_.last_
			)
		);
}

template<
	typename T,
	typename A
>
bool
fcppt::container::raw_vector::object<
	T,
	A
>::empty() const
noexcept
{
	return
		this->begin()
		==
		this->end();
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::size_type
fcppt::container::raw_vector::object<
	T,
	A
>::capacity() const
noexcept
{
	return
		fcppt::cast::to_unsigned(
			std::distance(
				impl_.first_,
				impl_.cap_
			)
		);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::swap(
	object &_other
)
noexcept
{
	std::swap(
		impl_.first_,
		_other.impl_.first_
	);

	std::swap(
		impl_.last_,
		_other.impl_.last_
	);

	std::swap(
		impl_.cap_,
		_other.impl_.cap_
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::resize(
	size_type const _size,
	T const &_value
)
{
	if(
		_size
		>
		this->size()
	)
		this->insert(
			this->end(),
			_size - this->size(),
			_value
		);
	else if(
		_size
		<
		this->size()
	)
		this->erase(
			this->begin() + _size,
			this->end()
		);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::reserve(
	size_type const _size
)
{
	if(
		_size
		<=
		this->capacity()
	)
		return;

	this->reallocate(
		this->new_capacity(
			_size
		)
	);
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::allocator_type
fcppt::container::raw_vector::object<
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
typename
fcppt::container::raw_vector::object<
	T,
	A
>::iterator
fcppt::container::raw_vector::object<
	T,
	A
>::insert(
	iterator const _position,
	T const &_value
)
{
	size_type const new_size(
		size() + 1u
	);

	if(
		new_size > this->capacity()
	)
	{
		difference_type const insert_sz(
			_position - this->begin()
		);

		size_type const new_cap(
			this->new_capacity(
				new_size
			)
		);

		pointer const new_memory(
			impl_.alloc_.allocate(
				new_cap,
				nullptr
			)
		);

		if(
			!this->empty()
		)
			std::uninitialized_copy(
				this->begin(),
				_position,
				new_memory
			);

		*(new_memory + insert_sz) = _value;

		if(
			!this->empty()
		)
			std::uninitialized_copy(
				_position,
				this->end(),
				new_memory + insert_sz + 1u
			);

		this->deallocate();

		this->set_pointers(
			new_memory,
			new_size,
			new_cap
		);

		return this->begin() + insert_sz;
	}
	else
	{
		if(
			!this->empty()
		)
			std::copy_backward(
				_position,
				this->end(),
				std::next(
					this->data_end()
				)
			);

		*_position = _value;

		++impl_.last_;

		return _position;
	}
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::insert(
	iterator const _position,
	size_type const _size,
	T const &_value
)
{
	size_type const new_size(
		this->size() + _size
	);

	if(
		new_size > this->capacity()
	)
	{
		difference_type const insert_sz(
			_position - this->begin()
		);

		size_type const new_cap(
			this->new_capacity(
				new_size
			)
		);

		pointer const new_memory(
			impl_.alloc_.allocate(
				new_cap,
				nullptr
			)
		);

		if(
			!this->empty()
		)
			std::uninitialized_copy(
				this->begin(),
				_position,
				new_memory
			);

		std::uninitialized_fill(
			new_memory + insert_sz,
			new_memory + insert_sz + _size,
			_value
		);

		if(
			!this->empty()
		)
			std::uninitialized_copy(
				_position,
				this->end(),
				new_memory + insert_sz + _size
			);

		this->deallocate();

		this->set_pointers(
			new_memory,
			new_size,
			new_cap
		);
	}
	else
	{
		if(
			!this->empty()
		)
			std::copy_backward(
				_position,
				this->end(),
				this->data_end() + _size
			);

		std::uninitialized_fill(
			_position,
			_position + _size,
			_value
		);

		impl_.last_ += _size;
	}
}

template<
	typename T,
	typename A
>
template<
	typename In
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::insert(
	iterator const _position,
	In const _left,
	In const _right
)
{
	if(
		_left
		==
		_right
	)
		return;

	this->insert_impl(
		_position,
		_left,
		_right
	);
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::iterator
fcppt::container::raw_vector::object<
	T,
	A
>::erase(
	iterator const _position
)
noexcept
{
	std::uninitialized_copy(
		_position + 1u,
		this->end(),
		_position
	);

	--impl_.last_;

	return
		_position;
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::iterator
fcppt::container::raw_vector::object<
	T,
	A
>::erase(
	iterator const _left,
	iterator const _right
)
noexcept
{
	if(
		_left
		!=
		_right
	)
	{
		std::uninitialized_copy(
			_right,
			this->end(),
			_left
		);

		impl_.last_ -=
			_right - _left;
	}

	return
		_right;
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::shrink_to_fit()
{
	this->reallocate(
		this->size()
	);
}

template<
	typename T,
	typename A
>
template<
	typename In
>
std::enable_if_t<
	!fcppt::type_traits::is_iterator_of_category<
		In,
		std::forward_iterator_tag
	>::value,
	void
>
fcppt::container::raw_vector::object<
	T,
	A
>::insert_impl(
	iterator _position,
	In _left,
	In const _right
)
{
	for(
		;
		_left != _right;
		++_left
	)
		_position =
			std::next(
				this->insert(
					_position,
					*_left
				)
			);
}

template<
	typename T,
	typename A
>
template<
	typename In
>
std::enable_if_t<
	fcppt::type_traits::is_iterator_of_category<
		In,
		std::forward_iterator_tag
	>::value,
	void
>
fcppt::container::raw_vector::object<
	T,
	A
>::insert_impl(
	iterator const _position,
	In const _left,
	In const _right
)
{
	difference_type const distance(
		std::distance(
			_left,
			_right
		)
	);

	size_type const new_size(
		this->size()
		+
		fcppt::cast::to_unsigned(
			distance
		)
	);

	if(
		new_size > this->capacity()
	)
	{
		difference_type const insert_sz(
			_position - this->begin()
		);

		size_type const new_cap(
			this->new_capacity(
				new_size
			)
		);

		pointer const new_memory(
			impl_.alloc_.allocate(
				new_cap
			)
		);

		if(
			!this->empty()
		)
			std::uninitialized_copy(
				this->begin(),
				_position,
				new_memory
			);

		std::uninitialized_copy(
			_left,
			_right,
			new_memory + insert_sz
		);

		if(
			!this->empty()
		)
			std::uninitialized_copy(
				_position,
				this->end(),
				new_memory + insert_sz + distance
			);

		this->deallocate();

		this->set_pointers(
			new_memory,
			new_size,
			new_cap
		);
	}
	else
	{
		if(
			!this->empty()
		)
			std::copy_backward(
				_position,
				this->end(),
				this->data_end() + distance
			);

		std::uninitialized_copy(
			_left,
			_right,
			_position
		);

		impl_.last_ += distance;
	}
}

template<
	typename T,
	typename A
>
typename
fcppt::container::raw_vector::object<
	T,
	A
>::size_type
fcppt::container::raw_vector::object<
	T,
	A
>::new_capacity(
	size_type const _new_size
) const
noexcept
{
	return
		std::max(
			_new_size,
			this->capacity()
			*
			2u
		);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::reallocate(
	size_type const _new_cap
)
{
	size_type const old_size(
		this->size()
	);

	pointer const new_memory(
		impl_.alloc_.allocate(
			_new_cap,
			nullptr
		)
	);

	if(
		!this->empty()
	)
		std::uninitialized_copy(
			this->begin(),
			this->end(),
			new_memory
		);

	this->deallocate();

	this->set_pointers(
		new_memory,
		old_size,
		_new_cap
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::set_pointers(
	pointer const _first,
	size_type const _size,
	size_type const _cap
)
noexcept
{
	impl_.first_ =
		_first;

	impl_.last_ =
		impl_.first_
		+
		_size;

	impl_.cap_ =
		impl_.first_
		+
		_cap;
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::object<
	T,
	A
>::deallocate()
noexcept
{
	if(
		impl_.first_
		!=
		nullptr
	)
		impl_.alloc_.deallocate(
			impl_.first_,
			this->capacity()
		);
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector::object<
	T,
	A
>::impl::impl(
	A const &_alloc
)
noexcept
:
	alloc_(
		_alloc
	),
	first_(
		nullptr
	),
	last_(
		nullptr
	),
	cap_(
		nullptr
	)
{
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector::object<
	T,
	A
>::impl::impl(
	fcppt::container::raw_vector::rep<
		A
	> const &_rep
)
noexcept
:
	alloc_{
		_rep.alloc()
	},
	first_{
		_rep.first()
	},
	last_{
		_rep.last()
	},
	cap_{
		_rep.cap()
	}
{
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector::object<
	T,
	A
>::impl::impl(
	impl &&_other
)
noexcept
:
	alloc_(
		_other.alloc_
	),
	first_(
		_other.first_
	),
	last_(
		_other.last_
	),
	cap_(
		_other.cap_
	)
{
	_other.reset_pointers();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector::object<
	T,
	A
>::impl &
fcppt::container::raw_vector::object<
	T,
	A
>::impl::operator=(
	impl &&_other
)
noexcept
{
	alloc_ =
		_other.alloc_;

	first_ =
		_other.first_;

	last_ =
		_other.last_;

	cap_ =
		_other.cap_;

	_other.reset_pointers();

	return
		*this;
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector::object<
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
fcppt::container::raw_vector::object<
	T,
	A
>::impl::reset_pointers()
noexcept
{
	first_ =
		nullptr;

	last_ =
		nullptr;

	cap_ =
		nullptr;
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector::swap(
	fcppt::container::raw_vector::object<
		T,
		A
	> &_x,
	fcppt::container::raw_vector::object<
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
