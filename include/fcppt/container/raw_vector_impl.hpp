//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_RAW_VECTOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_IMPL_HPP_INCLUDED

#include <fcppt/container/raw_vector_decl.hpp>
#include <fcppt/container/out_of_range.hpp>
#include <fcppt/type_traits/is_input_iterator.hpp>
#include <fcppt/assert.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/next_prior.hpp>
#include <iterator>
#include <algorithm>

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::iterator
fcppt::container::raw_vector<T, A>::begin()
{
	return data();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_iterator
fcppt::container::raw_vector<T, A>::begin() const
{
	return data();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::iterator
fcppt::container::raw_vector<T, A>::end()
{
	return data_end();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_iterator
fcppt::container::raw_vector<T, A>::end() const
{
	return data_end();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::reverse_iterator
fcppt::container::raw_vector<T, A>::rbegin()
{
	return reverse_iterator(end());
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_reverse_iterator
fcppt::container::raw_vector<T, A>::rbegin() const
{
	return const_reverse_iterator(end());
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::reverse_iterator
fcppt::container::raw_vector<T, A>::rend()
{
	return reverse_iterator(begin());
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_reverse_iterator
fcppt::container::raw_vector<T, A>::rend() const
{
	return const_reverse_iterator(begin());
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_iterator
fcppt::container::raw_vector<T, A>::cbegin() const
{
	return begin();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_iterator
fcppt::container::raw_vector<T, A>::cend() const
{
	return end();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_reverse_iterator
fcppt::container::raw_vector<T, A>::crbegin() const
{
	return rbegin();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_reverse_iterator
fcppt::container::raw_vector<T, A>::crend() const
{
	return rend();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::reference
fcppt::container::raw_vector<T, A>::operator[](
	size_type const _index
)
{
	return *(begin() + _index);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_reference
fcppt::container::raw_vector<T, A>::operator[](
	size_type const _index
) const
{
	return *(begin() + _index);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::reference
fcppt::container::raw_vector<T, A>::at(
	size_type const _index
)
{
	range_check(
		_index
	);

	return (*this)[_index];
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_reference
fcppt::container::raw_vector<T, A>::at(
	size_type const _index
) const
{
	range_check(
		_index
	);

	return (*this)[_index];
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::reference
fcppt::container::raw_vector<T, A>::front()
{
	return *begin();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_reference
fcppt::container::raw_vector<T, A>::front() const
{
	return *begin();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::reference
fcppt::container::raw_vector<T, A>::back()
{
	return *(boost::prior(end()));
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_reference
fcppt::container::raw_vector<T, A>::back() const
{
	return *(boost::prior(end()));
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::pointer
fcppt::container::raw_vector<T, A>::data()
{
	return impl_.first_;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_pointer
fcppt::container::raw_vector<T, A>::data() const
{
	return impl_.first_;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::pointer
fcppt::container::raw_vector<T, A>::data_end()
{
	return impl_.last_;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_pointer
fcppt::container::raw_vector<T, A>::data_end() const
{
	return impl_.last_;
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T, A>::raw_vector(
	A const &_alloc
)
:
	impl_(_alloc)
{}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T, A>::raw_vector(
	size_type const _size,
	A const &_alloc
)
:
	impl_(
		_alloc,
		_size
	)
{}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T, A>::raw_vector(
	size_type const _size,
	T const &_value,
	A const &_alloc
)
:
	impl_(
		_alloc
	)
{
	assign(
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
fcppt::container::raw_vector<T, A>::raw_vector(
	In const _begin,
	In const _end,
	A const &_alloc
)
:
	impl_(
		_alloc
	)
{
	assign(
		_begin,
		_end
	);
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T, A>::raw_vector(
	raw_vector const &_other
)
:
	impl_(
		_other.impl_.alloc_,
		_other.size()
	)
{
	assign(
		_other.begin(),
		_other.end()
	);
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T, A>::~raw_vector()
{
	deallocate();
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T, A> &
fcppt::container::raw_vector<T, A>::operator= (
	raw_vector const &_other
)
{
	if(
		&_other == this
	)
		return *this;
	
	assign(
		_other.begin(),
		_other.end()
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
fcppt::container::raw_vector<T, A>::assign(
	In const _begin,
	In const _end
)
{
	clear();

	insert(
		begin(),
		_begin,
		_end
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::assign(
	size_type const _size,
	T const &_value
)
{
	clear();

	insert(
		begin(),
		_size,
		_value
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::push_back(
	T const &_value
)
{
	insert(
		end(),
		_value
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::pop_back()
{
	erase(
		boost::prior(
			end()
		)
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::clear()
{
	erase(
		begin(),
		end()
	);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::size_type
fcppt::container::raw_vector<T, A>::size() const
{
	return
		static_cast<
			size_type
		>(
			impl_.last_
			- impl_.first_
		);
}

template<
	typename T,
	typename A
>
bool
fcppt::container::raw_vector<T, A>::empty() const
{
	return begin() == end();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::size_type
fcppt::container::raw_vector<T, A>::max_size() const
{
	return impl_.alloc_.max_size();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::size_type
fcppt::container::raw_vector<T, A>::capacity() const
{
	return
		static_cast<
			size_type
		>(
			impl_.cap_
			- impl_.first_
		);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::swap(
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
fcppt::container::raw_vector<T, A>::resize_uninitialized(
	size_type const _size
)
{
	if(
		_size > size()
	)
	{
		reserve(
			_size
		);

		impl_.last_ =
			impl_.first_
			+ _size;
	}
	else if(
		_size < size()
	)
		erase(
			begin() + _size,
			end()
		);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::resize(
	size_type const _size,
	T const &_value
)
{
	if(
		_size > size()
	)
		insert(
			end(),
			_size - size(),
			_value
		);
	else if(
		_size < size()
	)
		erase(
			begin() + _size,
			end()
		);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::reserve(
	size_type const _size
)
{
	if(
		_size <= capacity()
	)
		return;

	reallocate(
		new_capacity(
			_size
		)
	);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::allocator_type
fcppt::container::raw_vector<T, A>::get_allocator() const
{
	return impl_.alloc_;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::iterator
fcppt::container::raw_vector<T, A>::insert(
	iterator const _position,
	T const &_value
)
{
	size_type const new_size(
		size() + 1u
	);

	if(
		new_size > capacity()
	)
	{
		difference_type const insert_sz(
			_position - begin()
		);

		size_type const new_cap(
			new_capacity(
				new_size
			)
		);

		pointer const new_memory(
			impl_.alloc_.allocate(
				new_cap
			)
		);

		if(
			!empty()
		)
			std::uninitialized_copy(
				begin(),
				_position,
				new_memory
			);

		*(new_memory + insert_sz) = _value;

		if(
			!empty()
		)
			std::uninitialized_copy(
				_position,
				end(),
				new_memory + insert_sz + 1u
			);

		deallocate();

		set_pointers(
			new_memory,
			new_size,
			new_cap
		);

		return begin() + insert_sz;
	}
	else
	{
		if(
			!empty()
		)
			std::copy_backward(
				_position,
				end(),
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
fcppt::container::raw_vector<T, A>::insert(
	iterator const _position,
	size_type const _size,
	T const &_value
)
{
	size_type const new_size(
		size() + _size
	);

	if(
		new_size > capacity()
	)
	{
		difference_type const insert_sz(
			_position - begin()
		);

		size_type const new_cap(
			new_capacity(
				new_size
			)
		);

		pointer const new_memory(
			impl_.alloc_.allocate(
				new_cap
			)
		);

		if(
			!empty()
		)
			std::uninitialized_copy(
				begin(),
				_position,
				new_memory
			);

		std::uninitialized_fill(
			new_memory + insert_sz,
			new_memory + insert_sz + _size,
			_value
		);

		if(
			!empty()
		)
			std::uninitialized_copy(
				_position,
				end(),
				new_memory + insert_sz + _size
			);

		deallocate();

		set_pointers(
			new_memory,
			new_size,
			new_cap
		);
	}
	else
	{
		if(
			!empty()
		)
			std::copy_backward(
				_position,
				end(),
				data_end() + _size
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
fcppt::container::raw_vector<T, A>::insert(
	iterator const _position,
	In const _left,
	In const _right
)
{
	insert_impl(
		_position,
		_left,
		_right
	);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::iterator
fcppt::container::raw_vector<T, A>::erase(
	iterator const _position
)
{
	std::uninitialized_copy(
		_position + 1u,
		end(),
		_position
	);

	--impl_.last_;

	return _position;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::iterator
fcppt::container::raw_vector<T, A>::erase(
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
fcppt::container::raw_vector<T, A>::shrink_to_fit()
{
	reallocate(
		size()
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::free_memory()
{
	deallocate();

	set_pointers(
		0,
		0,
		0
	);
}

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
fcppt::container::raw_vector<T, A>::insert_impl(	
	iterator _position,
	In const _left,
	In _right
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
fcppt::container::raw_vector<T, A>::insert_impl(
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
		size() + static_cast<size_type>(distance)
	);

	if(
		new_size > capacity()
	)
	{
		difference_type const insert_sz(
			_position - begin()
		);

		size_type const new_cap(
			new_capacity(
				new_size
			)
		);

		pointer const new_memory(
			impl_.alloc_.allocate(
				new_cap
			)
		);

		if(
			!empty()
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
			!empty()
		)
			std::uninitialized_copy(
				_position,
				end(),
				new_memory + insert_sz + distance
			);

		deallocate();

		set_pointers(
			new_memory,
			new_size,
			new_cap
		);
	}
	else
	{
		if(
			!empty()
		)
			std::copy_backward(
				_position,
				end(),
				data_end() + distance
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
fcppt::container::raw_vector<T, A>::range_check(
	size_type const _index
) const
{
	if(
		_index >= size()
	)
		throw container::out_of_range();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::size_type
fcppt::container::raw_vector<T, A>::new_capacity(
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
fcppt::container::raw_vector<T, A>::reallocate(
	size_type const _new_cap
)
{
	FCPPT_ASSERT(
		_new_cap >= size()
	);

	size_type const old_size(
		size()
	);

	pointer const new_memory(
		impl_.alloc_.allocate(
			_new_cap
		)
	);

	if(
		!empty()
	)
		std::uninitialized_copy(
			begin(),
			end(),
			new_memory
		);

	deallocate();

	set_pointers(
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
fcppt::container::raw_vector<T, A>::set_pointers(
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
fcppt::container::raw_vector<T, A>::deallocate()
{
	if(
		!empty()
	)
		impl_.alloc_.deallocate(
			impl_.first_,
			capacity()
		);
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T,A>::impl::impl(
	A const &_alloc
)
:
	alloc_(_alloc),
	first_(0),
	last_(0),
	cap_(0)
{}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T,A>::impl::impl(
	A const &_alloc,
	size_type const _size
)
:
	alloc_(
		_alloc
	),
	first_(
		alloc_.allocate(
			_size
		)
	),
	last_(
		first_ + _size
	),
	cap_(
		last_
	)
{}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator==(
	raw_vector<T, A> const &_left,
	raw_vector<T, A> const &_right
)
{
	return
		_left.size() == _right.size()
		&& std::equal(
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
	raw_vector<T, A> const &_left,
	raw_vector<T, A> const &_right
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
	raw_vector<T, A> const &_left,
	raw_vector<T, A> const &_right
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
	raw_vector<T, A> const &_left,
	raw_vector<T, A> const &_right
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
	raw_vector<T, A> const &_left,
	raw_vector<T, A> const &_right
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
	raw_vector<T, A> const &_left,
	raw_vector<T, A> const &_right
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
	raw_vector<T, A> &_x,
	raw_vector<T, A> &_y
)
{
	_x.swap(
		_y
	);
}

#endif
