//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_RAW_VECTOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_IMPL_HPP_INCLUDED

#include <fcppt/assert/pre.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/out_of_range.hpp>
#include <fcppt/container/raw_vector_decl.hpp>
#include <fcppt/detail/equal.hpp>
#include <fcppt/type_traits/is_input_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::iterator
fcppt::container::raw_vector<
	T,
	A
>::begin()
{
	return this->data();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_iterator
fcppt::container::raw_vector<
	T,
	A
>::begin() const
{
	return this->data();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::iterator
fcppt::container::raw_vector<
	T,
	A
>::end()
{
	return this->data_end();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_iterator
fcppt::container::raw_vector<
	T,
	A
>::end() const
{
	return this->data_end();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::reverse_iterator
fcppt::container::raw_vector<
	T,
	A
>::rbegin()
{
	return
		reverse_iterator(
			this->end()
		);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_reverse_iterator
fcppt::container::raw_vector<
	T,
	A
>::rbegin() const
{
	return
		const_reverse_iterator(
			this->end()
		);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::reverse_iterator
fcppt::container::raw_vector<
	T,
	A
>::rend()
{
	return
		reverse_iterator(
			this->begin()
		);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_reverse_iterator
fcppt::container::raw_vector<
	T,
	A
>::rend() const
{
	return
		const_reverse_iterator(
			this->begin()
		);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_iterator
fcppt::container::raw_vector<
	T,
	A
>::cbegin() const
{
	return this->begin();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_iterator
fcppt::container::raw_vector<
	T,
	A
>::cend() const
{
	return this->end();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_reverse_iterator
fcppt::container::raw_vector<
	T,
	A
>::crbegin() const
{
	return this->rbegin();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_reverse_iterator
fcppt::container::raw_vector<
	T,
	A
>::crend() const
{
	return this->rend();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::reference
fcppt::container::raw_vector<
	T,
	A
>::operator[](
	size_type const _index
)
{
	return *(this->begin() + _index);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_reference
fcppt::container::raw_vector<
	T,
	A
>::operator[](
	size_type const _index
) const
{
	return *(this->begin() + _index);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::reference
fcppt::container::raw_vector<
	T,
	A
>::at(
	size_type const _index
)
{
	this->range_check(
		_index
	);

	return (*this)[_index];
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_reference
fcppt::container::raw_vector<
	T,
	A
>::at(
	size_type const _index
) const
{
	this->range_check(
		_index
	);

	return (*this)[_index];
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::reference
fcppt::container::raw_vector<
	T,
	A
>::front()
{
	return *this->begin();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_reference
fcppt::container::raw_vector<
	T,
	A
>::front() const
{
	return *this->begin();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::reference
fcppt::container::raw_vector<
	T,
	A
>::back()
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
typename fcppt::container::raw_vector<
	T,
	A
>::const_reference
fcppt::container::raw_vector<
	T,
	A
>::back() const
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
typename fcppt::container::raw_vector<
	T,
	A
>::pointer
fcppt::container::raw_vector<
	T,
	A
>::data()
{
	return impl_.first_;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_pointer
fcppt::container::raw_vector<
	T,
	A
>::data() const
{
	return impl_.first_;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::pointer
fcppt::container::raw_vector<
	T,
	A
>::data_end()
{
	return impl_.last_;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::const_pointer
fcppt::container::raw_vector<
	T,
	A
>::data_end() const
{
	return impl_.last_;
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<
	T,
	A
>::raw_vector(
	A const &_alloc
)
:
	impl_(
		_alloc
	)
{
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<
	T,
	A
>::raw_vector(
	size_type const _size,
	A const &_alloc
)
:
	impl_(
		_alloc,
		_size
	)
{
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<
	T,
	A
>::raw_vector(
	size_type const _size,
	T const &_value,
	A const &_alloc
)
:
	impl_(
		_alloc
	)
{
	this->assign(
		_size,
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
fcppt::container::raw_vector<
	T,
	A
>::raw_vector(
	In const _begin,
	In const _end,
	A const &_alloc
)
:
	impl_(
		_alloc
	)
{
	this->assign(
		_begin,
		_end
	);
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<
	T,
	A
>::raw_vector(
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
	this->assign(
		_inits.begin(),
		_inits.end()
	);
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<
	T,
	A
>::raw_vector(
	raw_vector const &_other
)
:
	impl_(
		_other.impl_.alloc_,
		_other.size()
	)
{
	this->assign(
		_other.begin(),
		_other.end()
	);
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<
	T,
	A
>::raw_vector(
	raw_vector &&_other
)
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
fcppt::container::raw_vector<
	T,
	A
>::~raw_vector()
{
	this->deallocate();
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<
	T,
	A
> &
fcppt::container::raw_vector<
	T,
	A
>::operator=(
	raw_vector const &_other
)
{
	if(
		&_other == this
	)
		return *this;

	this->assign(
		_other.begin(),
		_other.end()
	);

	return *this;
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<
	T,
	A
> &
fcppt::container::raw_vector<
	T,
	A
>::operator=(
	raw_vector &&_other
)
{
	impl_ =
		std::move(
			_other.impl_
		);

	return *this;
}

template<
	typename T,
	typename A
>
template<
	typename In
>
void
fcppt::container::raw_vector<
	T,
	A
>::assign(
	In const _begin,
	In const _end
)
{
	this->clear();

	this->insert(
		this->begin(),
		_begin,
		_end
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<
	T,
	A
>::assign(
	size_type const _size,
	T const &_value
)
{
	this->clear();

	this->insert(
		this->begin(),
		_size,
		_value
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<
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
fcppt::container::raw_vector<
	T,
	A
>::pop_back()
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
fcppt::container::raw_vector<
	T,
	A
>::clear()
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
typename fcppt::container::raw_vector<
	T,
	A
>::size_type
fcppt::container::raw_vector<
	T,
	A
>::size() const
{
	return
		fcppt::cast::to_unsigned(
			impl_.last_
			-
			impl_.first_
		);
}

template<
	typename T,
	typename A
>
bool
fcppt::container::raw_vector<
	T,
	A
>::empty() const
{
	return
		this->begin() == this->end();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::size_type
fcppt::container::raw_vector<
	T,
	A
>::max_size() const
{
	return impl_.alloc_.max_size();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::size_type
fcppt::container::raw_vector<
	T,
	A
>::capacity() const
{
	return
		fcppt::cast::to_unsigned(
			impl_.cap_
			-
			impl_.first_
		);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<
	T,
	A
>::swap(
	raw_vector &_other
)
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
fcppt::container::raw_vector<
	T,
	A
>::resize_uninitialized(
	size_type const _size
)
{
	if(
		_size > this->size()
	)
	{
		this->reserve(
			_size
		);

		impl_.last_ =
			impl_.first_
			+ _size;
	}
	else if(
		_size < this->size()
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
fcppt::container::raw_vector<
	T,
	A
>::resize(
	size_type const _size,
	T const &_value
)
{
	if(
		_size > this->size()
	)
		this->insert(
			this->end(),
			_size - size(),
			_value
		);
	else if(
		_size < this->size()
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
fcppt::container::raw_vector<
	T,
	A
>::reserve(
	size_type const _size
)
{
	if(
		_size <= this->capacity()
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
typename fcppt::container::raw_vector<
	T,
	A
>::allocator_type
fcppt::container::raw_vector<
	T,
	A
>::get_allocator() const
{
	return impl_.alloc_;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::iterator
fcppt::container::raw_vector<
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
				data_end() + 1u
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
fcppt::container::raw_vector<
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
fcppt::container::raw_vector<
	T,
	A
>::insert(
	iterator const _position,
	In const _left,
	In const _right
)
{
	if(
		_left == _right
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
typename fcppt::container::raw_vector<
	T,
	A
>::iterator
fcppt::container::raw_vector<
	T,
	A
>::erase(
	iterator const _position
)
{
	std::uninitialized_copy(
		_position + 1u,
		this->end(),
		_position
	);

	--impl_.last_;

	return _position;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::iterator
fcppt::container::raw_vector<
	T,
	A
>::erase(
	iterator const _left,
	iterator const _right
)
{
	if(
		_left != _right
	)
	{
		std::uninitialized_copy(
			_right, end(),
			_left
		);

		impl_.last_ -= _right - _left;
	}

	return _right;
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<
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
void
fcppt::container::raw_vector<
	T,
	A
>::free_memory()
{
	this->deallocate();

	this->set_pointers(
		nullptr,
		0u,
		0u
	);
}

// I've commented out the private section, so I have to do it here, too
/// \cond
template<
	typename T,
	typename A
>
template<
	typename In
>
typename boost::enable_if<
	fcppt::type_traits::is_input_iterator<
		In
	>,
	void
>::type
fcppt::container::raw_vector<
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
			this->insert(
				_position,
				*_left
			)
			+ 1;
}

template<
	typename T,
	typename A
>
template<
	typename In
>
typename boost::disable_if<
	fcppt::type_traits::is_input_iterator<
		In
	>,
	void
>::type
fcppt::container::raw_vector<
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
				begin(),
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
void
fcppt::container::raw_vector<
	T,
	A
>::range_check(
	size_type const _index
) const
{
	if(
		_index >= this->size()
	)
		throw container::out_of_range();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::size_type
fcppt::container::raw_vector<
	T,
	A
>::new_capacity(
	size_type const _new_size
) const
{
	return
		std::max(
			_new_size,
			capacity() * 2u
		);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<
	T,
	A
>::reallocate(
	size_type const _new_cap
)
{
	FCPPT_ASSERT_PRE(
		_new_cap >= this->size()
	);

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
fcppt::container::raw_vector<
	T,
	A
>::set_pointers(
	pointer const _first,
	size_type const _size,
	size_type const _cap
)
{
	impl_.first_ = _first;

	impl_.last_ = impl_.first_ + _size;

	impl_.cap_ = impl_.first_ + _cap;
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<
	T,
	A
>::deallocate()
{
	if(
		this->capacity() != 0u
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
fcppt::container::raw_vector<
	T,
	A
>::impl::impl(
	A const &_alloc
)
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
fcppt::container::raw_vector<
	T,
	A
>::impl::impl(
	impl &&_other
)
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
fcppt::container::raw_vector<
	T,
	A
>::impl::impl(
	A const &_alloc,
	size_type const _size
)
:
	alloc_(
		_alloc
	),
	first_(
		_size == 0u
		?
			nullptr
		:
			alloc_.allocate(
				_size,
				nullptr
			)
	),
	last_(
		first_ + _size
	),
	cap_(
		last_
	)
{
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<
	T,
	A
>::impl &
fcppt::container::raw_vector<
	T,
	A
>::impl::operator=(
	impl &&_other
)
{
	alloc_ = _other.alloc_;

	first_ = _other.first_;

	last_ = _other.last_;

	cap_ = _other.cap_;

	_other.reset_pointers();

	return *this;
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<
	T,
	A
>::impl::~impl()
{
}


template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<
	T,
	A
>::impl::reset_pointers()
{
	first_ = nullptr;

	last_ = nullptr;

	cap_ = nullptr;
}

/// \endcond

template<
	typename T,
	typename A
>
bool
fcppt::container::operator==(
	fcppt::container::raw_vector<
		T,
		A
	> const &_left,
	fcppt::container::raw_vector<
		T,
		A
	> const &_right
)
{
	return
		_left.size() == _right.size()
		&&
		fcppt::detail::equal(
			_left.begin(),
			_left.end(),
			_right.begin()
		);
}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator<(
	fcppt::container::raw_vector<
		T,
		A
	> const &_left,
	fcppt::container::raw_vector<
		T,
		A
	> const &_right
)
{
	return
		std::lexicographical_compare(
			_left.begin(),
			_left.end(),
			_right.begin(),
			_right.end()
		);
}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator!=(
	fcppt::container::raw_vector<
		T,
		A
	> const &_left,
	fcppt::container::raw_vector<
		T,
		A
	> const &_right
)
{
	return !(_left == _right);
}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator>(
	raw_vector<
	T,
	A
> const &_left,
	raw_vector<
	T,
	A
> const &_right
)
{
	return _right < _left;
}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator>=(
	fcppt::container::raw_vector<
		T,
		A
	> const &_left,
	fcppt::container::raw_vector<
		T,
		A
	> const &_right
)
{
	return !(_left < _right);
}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator<=(
	fcppt::container::raw_vector<
		T,
		A
	> const &_left,
	fcppt::container::raw_vector<
		T,
		A
	> const &_right
)
{
	return !(_left > _right);
}

template<
	typename T,
	typename A
>
void
fcppt::container::swap(
	fcppt::container::raw_vector<
		T,
		A
	> &_x,
	fcppt::container::raw_vector<
		T,
		A
	> &_y
)
{
	_x.swap(
		_y
	);
}

#endif
