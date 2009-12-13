/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_CONTAINER_RAW_VECTOR_IMPL_HPP_INCLUDED
#define SGE_CONTAINER_RAW_VECTOR_IMPL_HPP_INCLUDED

#include <sge/container/raw_vector_decl.hpp>
#include <sge/assert.hpp>
#include <boost/next_prior.hpp>
#include <iterator>
#include <algorithm>

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::iterator
sge::container::raw_vector<T, A>::begin()
{
	return data();
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::const_iterator
sge::container::raw_vector<T, A>::begin() const
{
	return data();
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::iterator
sge::container::raw_vector<T, A>::end()
{
	return data_end();
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::const_iterator sge::container::raw_vector<T, A>::end() const
{
	return data_end();
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::reverse_iterator sge::container::raw_vector<T, A>::rbegin()
{
	return reverse_iterator(end());
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::const_reverse_iterator sge::container::raw_vector<T, A>::rbegin() const
{
	return const_reverse_iterator(end());
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::reverse_iterator sge::container::raw_vector<T, A>::rend()
{
	return reverse_iterator(begin());
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::const_reverse_iterator sge::container::raw_vector<T, A>::rend() const
{
	return const_reverse_iterator(begin());
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::reference sge::container::raw_vector<T, A>::operator[] (const size_type n)
{
	return *(begin() + n);
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::const_reference sge::container::raw_vector<T, A>::operator[] (const size_type n) const
{
	return *(begin() + n);
}

template<typename T, typename A>
void sge::container::raw_vector<T, A>::free_memory()
{
	deallocate();
	set_pointers(0, 0, 0);
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::reference sge::container::raw_vector<T, A>::at(const size_type n)
{
	range_check(n);
	return (*this)[n];
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::const_reference sge::container::raw_vector<T, A>::at(const size_type n) const
{
	range_check(n);
	return (*this)[n];
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::reference sge::container::raw_vector<T, A>::front()
{
	return *begin();
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::const_reference sge::container::raw_vector<T, A>::front() const
{
	return *begin();
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::reference sge::container::raw_vector<T, A>::back()
{
	return *(boost::prior(end()));
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::const_reference sge::container::raw_vector<T, A>::back() const
{
	return *(boost::prior(end()));
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::pointer
sge::container::raw_vector<T, A>::data()
{
	return i.first;
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::const_pointer
sge::container::raw_vector<T, A>::data() const
{
	return i.first;
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::pointer
sge::container::raw_vector<T, A>::data_end()
{
	return i.last;
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::const_pointer
sge::container::raw_vector<T, A>::data_end() const
{
	return i.last;
}

template<typename T, typename A>
sge::container::raw_vector<T, A>::raw_vector(const A& a)
:
	i(a)
{}

template<typename T, typename A>
sge::container::raw_vector<T, A>::raw_vector(const size_type sz, const A& a)
: i(a, sz)
{}

template<typename T, typename A>
sge::container::raw_vector<T, A>::raw_vector(const size_type sz, const T& t, const A& a)
: i(a, sz)
{
	assign(sz, t);
}

template<typename T, typename A>
template<typename In>
sge::container::raw_vector<T, A>::raw_vector(const In beg, const In end, const A& a)
: i(a)
{
	assign(beg, end);
}

template<typename T, typename A>
sge::container::raw_vector<T, A>::raw_vector(const raw_vector& x)
: i(x.i.a, x.size())
{
	assign(x.begin(), x.end());
}

template<typename T, typename A>
sge::container::raw_vector<T, A>::~raw_vector()
{
	deallocate();
}

template<typename T, typename A>
sge::container::raw_vector<T, A>& sge::container::raw_vector<T, A>::operator= (const raw_vector& x)
{
	if(&x == this)
		return *this;
	assign(x.begin(), x.end());
	return *this;
}

template<typename T, typename A>
template<typename In>
void sge::container::raw_vector<T, A>::assign(const In beg, const In end)
{
	clear();
	insert(begin(), beg, end);
}

template<typename T, typename A>
void sge::container::raw_vector<T, A>::assign(const size_type n, const T& value)
{
	clear();
	insert(begin(), n, value);
}

template<typename T, typename A>
void sge::container::raw_vector<T, A>::push_back(const T& x)
{
	insert(end(), x);
}

template<typename T, typename A>
void sge::container::raw_vector<T, A>::pop_back()
{
	erase(boost::prior(end()));
}

template<typename T, typename A>
void sge::container::raw_vector<T, A>::clear()
{
	erase(begin(), end());
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::size_type sge::container::raw_vector<T, A>::size() const
{
	return i.last - i.first;
}

template<typename T, typename A>
bool sge::container::raw_vector<T, A>::empty() const
{
	return size() == 0;
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::size_type sge::container::raw_vector<T, A>::max_size() const
{
	return i.a.max_size();
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::size_type sge::container::raw_vector<T, A>::capacity() const
{
	return i.cap - i.first;
}

template<typename T, typename A>
void sge::container::raw_vector<T, A>::swap(raw_vector& x)
{
	std::swap(i.first, x.i.first);
	std::swap(i.last, x.i.last);
	std::swap(i.cap, x.i.cap);
}

template<typename T, typename A>
void sge::container::raw_vector<T, A>::resize_uninitialized(const size_type sz)
{
	if(sz > size())
	{
		reserve(sz);
		i.last = i.first + sz;
	}
	else if(sz < size())
		erase(begin() + sz, end());
}

template<typename T, typename A>
void sge::container::raw_vector<T, A>::resize(const size_type sz, const T& value)
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
void sge::container::raw_vector<T, A>::reserve(
	size_type const sz)
{
	if(sz <= capacity())
		return;

	size_type const
		new_cap = new_capacity(sz),
		old_size = size();

	pointer const new_memory = i.a.allocate(new_cap);

	if(!empty())
		std::uninitialized_copy(begin(), end(), new_memory);

	deallocate();
	set_pointers(new_memory, old_size, new_cap);
}

template <typename T, typename A>
typename sge::container::raw_vector<T, A>::allocator_type sge::container::raw_vector<T, A>::get_allocator() const
{
	return i.a;
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::iterator
sge::container::raw_vector<T, A>::insert(
	iterator const position,
	T const &x)
{
	size_type const new_size = size() + 1;
	if(new_size > capacity())
	{
		difference_type const insert_sz = position - begin();
		size_type const new_cap = new_capacity(new_size);
		pointer const new_memory = i.a.allocate(new_cap);
		if(!empty())
			std::uninitialized_copy(begin(), position, new_memory);
		*(new_memory + insert_sz) = x;
		if(!empty())
			std::uninitialized_copy(position, end(), new_memory + insert_sz + 1);
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
				data_end() + 1
			);

		*position = x;
		i.last += 1;
		return position;
	}
}

template<typename T, typename A>
void sge::container::raw_vector<T, A>::insert(const iterator position, const size_type n, const T& x)
{
	const size_type new_size = size() + n;
	if(new_size > capacity())
	{
		const difference_type insert_sz = position - begin();
		const size_type new_cap = new_capacity(new_size);
		const pointer new_memory = i.a.allocate(new_cap);
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
sge::container::raw_vector<T, A>::insert(
	iterator const position,
	In const l,
	In const r)
{
	difference_type const distance(
		std::distance(l, r)
	);

	size_type const new_size = size() + distance;
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

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::iterator
sge::container::raw_vector<T, A>::erase(iterator const position)
{
	std::uninitialized_copy(position + 1, end(), position);
	--i.last;
	return position;
}

template<
	typename T,
	typename A
>
typename sge::container::raw_vector<T, A>::iterator
sge::container::raw_vector<T, A>::erase(
	iterator const l,
	iterator const r)
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
void sge::container::raw_vector<T, A>::range_check(
	size_type const n) const
{
	SGE_ASSERT(n < size());
}

template<typename T, typename A>
typename sge::container::raw_vector<T, A>::size_type
sge::container::raw_vector<T, A>::new_capacity(
	size_type const new_size) const
{
	return std::max(new_size, capacity() * 2);
}

template<typename T, typename A>
void sge::container::raw_vector<T, A>::set_pointers(const pointer src, const size_type sz, const size_type cap_)
{
	i.first = src;
	i.last = i.first + sz;
	i.cap = i.first + cap_;
}

template<typename T, typename A>
void sge::container::raw_vector<T, A>::deallocate()
{
	if(!empty())
		i.a.deallocate(i.first, capacity());
}

template<typename T, typename A>
sge::container::raw_vector<T,A>::impl::impl(const A& a)
:
	a(a),
	first(0),
	last(0),
	cap(0)
{}

template<typename T, typename A>
sge::container::raw_vector<T,A>::impl::impl(const A& a_, const size_type sz)
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
sge::container::operator==(
	raw_vector<T, A> const &x,
	raw_vector<T,A> const &y)
{
	return x.size() == y.size() && std::equal(x.begin(), x.end(), y.begin());
}

template <typename T, typename A>
bool sge::container::operator< (const raw_vector<T, A>& x, const raw_vector<T, A>& y)
{
	return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <typename T, typename A>
bool sge::container::operator!=(const raw_vector<T, A>& x, const raw_vector<T, A>& y)
{
	return !(x == y);
}

template <typename T, typename A>
bool sge::container::operator> (const raw_vector<T, A>& x, const raw_vector<T, A>& y)
{
	return y < x;
}

template <typename T, typename A>
bool sge::container::operator>=(const raw_vector<T, A>& x, const raw_vector<T, A>& y)
{
	return !(x < y);
}

template <typename T, typename A>
bool sge::container::operator<=(const raw_vector<T, A>& x, const raw_vector<T, A>& y)
{
	return !(x > y);
}

template <typename T, typename A>
void sge::container::swap(raw_vector<T, A>& x, raw_vector<T, A>& y)
{
	x.swap(y);
}

#endif
