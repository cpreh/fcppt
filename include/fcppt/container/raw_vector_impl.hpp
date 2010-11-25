//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_RAW_VECTOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_IMPL_HPP_INCLUDED

#include <fcppt/container/raw_vector_decl.hpp>
#include <fcppt/container/out_of_range.hpp>
#include <fcppt/assert.hpp>
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
fcppt::container::raw_vector<T, A>::operator[] (
	size_type const n
)
{
	return *(begin() + n);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_reference
fcppt::container::raw_vector<T, A>::operator[](
	size_type const n
) const
{
	return *(begin() + n);
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::reference
fcppt::container::raw_vector<T, A>::at(
	size_type const n
)
{
	range_check(n);
	return (*this)[n];
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_reference
fcppt::container::raw_vector<T, A>::at(
	size_type const n
) const
{
	range_check(n);
	return (*this)[n];
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
	return i.first;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_pointer
fcppt::container::raw_vector<T, A>::data() const
{
	return i.first;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::pointer
fcppt::container::raw_vector<T, A>::data_end()
{
	return i.last;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::const_pointer
fcppt::container::raw_vector<T, A>::data_end() const
{
	return i.last;
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T, A>::raw_vector(
	A const &a
)
:
	i(a)
{}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T, A>::raw_vector(
	size_type const sz,
	A const &a
)
:
	i(a, sz)
{}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T, A>::raw_vector(
	size_type const sz,
	T const &t,
	A const &a
)
:
	i(a)
{
	assign(sz, t);
}

template<
	typename T,
	typename A
>
template<
	typename In
>
fcppt::container::raw_vector<T, A>::raw_vector(
	In const beg,
	In const end,
	A const &a
)
:
	i(a)
{
	assign(beg, end);
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T, A>::raw_vector(
	raw_vector const &x
)
:
	i(x.i.a, x.size())
{
	assign(x.begin(), x.end());
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
	raw_vector const &x
)
{
	if(&x == this)
		return *this;
	
	assign(
		x.begin(),
		x.end()
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
	In const beg,
	In const end
)
{
	clear();
	insert(begin(), beg, end);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::assign(
	size_type const n,
	T const &value
)
{
	clear();
	insert(begin(), n, value);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::push_back(
	T const &x
)
{
	insert(end(), x);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::pop_back()
{
	erase(boost::prior(end()));
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::clear()
{
	erase(begin(), end());
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
			i.last - i.first
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
	return i.a.max_size();
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
			i.cap - i.first
		);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::swap(
	raw_vector &x
)
{
	std::swap(i.first, x.i.first);
	std::swap(i.last, x.i.last);
	std::swap(i.cap, x.i.cap);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::resize_uninitialized(
	size_type const sz
)
{
	if(sz > size())
	{
		reserve(sz);
		i.last = i.first + sz;
	}
	else if(sz < size())
		erase(begin() + sz, end());
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::resize(
	size_type const sz,
	T const &value
)
{
	if(sz > size())
		insert(end(), sz - size(), value);
	else if(sz < size())
		erase(begin() + sz, end());
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::reserve(
	size_type const sz
)
{
	if(sz <= capacity())
		return;

	reallocate(
		new_capacity(
			sz
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
	return i.a;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::iterator
fcppt::container::raw_vector<T, A>::insert(
	iterator const position,
	T const &x
)
{
	size_type const new_size = size() + 1u;

	if(new_size > capacity())
	{
		difference_type const insert_sz = position - begin();
		size_type const new_cap = new_capacity(new_size);
		pointer const new_memory = i.a.allocate(new_cap);
		if(!empty())
			std::uninitialized_copy(begin(), position, new_memory);
		*(new_memory + insert_sz) = x;
		if(!empty())
			std::uninitialized_copy(position, end(), new_memory + insert_sz + 1u);
		deallocate();
		set_pointers(new_memory, new_size, new_cap);
		return begin() + insert_sz;
	}
	else
	{
		if(!empty())
			std::copy_backward(
				position,
				end(),
				data_end() + 1u
			);

		*position = x;
		++i.last;
		return position;
	}
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::insert(
	iterator const position,
	size_type const n,
	T const &x
)
{
	size_type const new_size = size() + n;

	if(new_size > capacity())
	{
		difference_type const insert_sz = position - begin();
		size_type const new_cap = new_capacity(new_size);
		pointer const new_memory = i.a.allocate(new_cap);
		if(!empty())
			std::uninitialized_copy(begin(), position, new_memory);
		std::uninitialized_fill(new_memory + insert_sz, new_memory + insert_sz + n, x);
		if(!empty())
			std::uninitialized_copy(position, end(), new_memory + insert_sz + n);
		deallocate();
		set_pointers(new_memory, new_size, new_cap);
	}
	else
	{
		if(!empty())
			std::copy_backward(
				position,
				end(),
				data_end() + n
			);

		std::uninitialized_fill(position, position + n, x);
		i.last += n;
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
	iterator const position,
	In const l,
	In const r
)
{
	difference_type const distance(
		std::distance(l, r)
	);

	size_type const new_size = size() + static_cast<size_type>(distance);
	if(new_size > capacity())
	{
		difference_type const insert_sz = position - begin();
		size_type const new_cap = new_capacity(new_size);
		pointer const new_memory = i.a.allocate(new_cap);
		if(!empty())
			std::uninitialized_copy(begin(), position, new_memory);
		std::uninitialized_copy(l, r, new_memory + insert_sz);
		if(!empty())
			std::uninitialized_copy(position, end(), new_memory + insert_sz + distance);
		deallocate();
		set_pointers(new_memory, new_size, new_cap);
	}
	else
	{
		if(!empty())
			std::copy_backward(
				position,
				end(),
				data_end() + distance
			);

		std::uninitialized_copy(l, r, position);
		i.last += distance;
	}
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::iterator
fcppt::container::raw_vector<T, A>::erase(
	iterator const position
)
{
	std::uninitialized_copy(
		position + 1u,
		end(),
		position
	);

	--i.last;

	return position;
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::iterator
fcppt::container::raw_vector<T, A>::erase(
	iterator const l,
	iterator const r
)
{
	if(l != r)
	{
		std::uninitialized_copy(r, end(), l);
		i.last -= r - l;
	}
	return r;
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
	set_pointers(0, 0, 0);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::range_check(
	size_type const n
) const
{
	if(
		n >= size()
	)
		throw container::out_of_range();
}

template<
	typename T,
	typename A
>
typename fcppt::container::raw_vector<T, A>::size_type
fcppt::container::raw_vector<T, A>::new_capacity(
	size_type const new_size
) const
{
	return std::max(
		new_size,
		capacity() * 2u
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::reallocate(
	size_type const new_cap
)
{
	FCPPT_ASSERT(new_cap >= size());

	size_type const old_size(
		size()
	);

	pointer const new_memory = i.a.allocate(new_cap);

	if(!empty())
		std::uninitialized_copy(
			begin(),
			end(),
			new_memory
		);

	deallocate();

	set_pointers(
		new_memory,
		old_size,
		new_cap
	);
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::set_pointers(
	pointer const src,
	size_type const sz,
	size_type const cap_
)
{
	i.first = src;
	i.last = i.first + sz;
	i.cap = i.first + cap_;
}

template<
	typename T,
	typename A
>
void
fcppt::container::raw_vector<T, A>::deallocate()
{
	if(!empty())
		i.a.deallocate(i.first, capacity());
}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T,A>::impl::impl(
	A const &a
)
:
	a(a),
	first(0),
	last(0),
	cap(0)
{}

template<
	typename T,
	typename A
>
fcppt::container::raw_vector<T,A>::impl::impl(
	A const &a_,
	size_type const sz
)
:
	a(a_),
	first(a.allocate(sz)),
	last(first + sz),
	cap(last)
{}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator==(
	raw_vector<T, A> const &x,
	raw_vector<T, A> const &y
)
{
	return
		x.size() == y.size()
		&& std::equal(
			x.begin(),
			x.end(),
			y.begin()
		);
}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator<(
	raw_vector<T, A> const &x,
	raw_vector<T, A> const &y
)
{
	return
		std::lexicographical_compare(
			x.begin(),
			x.end(),
			y.begin(),
			y.end()
		);
}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator!=(
	raw_vector<T, A> const &x,
	raw_vector<T, A> const &y
)
{
	return !(x == y);
}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator>(
	raw_vector<T, A> const &x,
	raw_vector<T, A> const &y
)
{
	return y < x;
}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator>=(
	raw_vector<T, A> const &x,
	raw_vector<T, A> const &y
)
{
	return !(x < y);
}

template<
	typename T,
	typename A
>
bool
fcppt::container::operator<=(
	raw_vector<T, A> const &x,
	raw_vector<T, A> const &y
)
{
	return !(x > y);
}

template<
	typename T,
	typename A
>
void
fcppt::container::swap(
	raw_vector<T, A> &x,
	raw_vector<T, A> &y
)
{
	x.swap(y);
}

#endif
