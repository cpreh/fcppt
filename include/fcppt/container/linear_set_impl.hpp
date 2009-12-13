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


#ifndef SGE_CONTAINER_LINEAR_SET_IMPL_HPP_INCLUDED
#define SGE_CONTAINER_LINEAR_SET_IMPL_HPP_INCLUDED

#include <sge/container/linear_set.hpp>
// std::swap
#include <algorithm>
#include <utility>

template<class T,class Compare,class Allocator>
sge::container::linear_set<T,Compare,Allocator>::linear_set(
	Compare const &key_comp_,
	Allocator const &alloc_)
	: comp_(key_comp_),
	  container_(alloc_)
{
}

template<class T,class Compare,class Allocator>
sge::container::linear_set<T,Compare,Allocator>::linear_set(
	linear_set const &lm)
	: comp_(lm.key_comp()),
	  container_(lm.container_)
{
}

template<class T,class Compare,class Allocator>
sge::container::linear_set<T,Compare,Allocator> &
	sge::container::linear_set<T,Compare,Allocator>::operator=(linear_set const &r)
{
	clear();
	insert(r.begin(),r.end());
	comp_ = r.comp_;
	return *this;
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::allocator_type sge::container::linear_set<T,Compare,Allocator>::get_allocator() const
{
	return container_.get_allocator();
}

template<class T,class Compare,class Allocator>
template<typename InputIterator>
sge::container::linear_set<T,Compare,Allocator>::linear_set(
	InputIterator const begin,
	InputIterator const last,
	Compare const &key_comp_,
	Allocator const &alloc_)
	: comp_(key_comp_),
	  container_(alloc_)
{
	insert(begin,last);
}

template<class T,class Compare,class Allocator>
template<typename InputIterator>
void sge::container::linear_set<T,Compare,Allocator>::insert(InputIterator it,InputIterator const last)
{
	for (;it != last; ++it)
		insert(*it);
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::reverse_iterator
	sge::container::linear_set<T,Compare,Allocator>::rbegin()
{
	return container_.rbegin();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::const_reverse_iterator
	sge::container::linear_set<T,Compare,Allocator>::rbegin() const
{
	return container_.rbegin();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::reverse_iterator
	sge::container::linear_set<T,Compare,Allocator>::rend()
{
	return container_.rend();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::const_reverse_iterator
	sge::container::linear_set<T,Compare,Allocator>::rend() const
{
	return container_.rend();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::iterator
	sge::container::linear_set<T,Compare,Allocator>::begin()
{
	return container_.begin();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::const_iterator
	sge::container::linear_set<T,Compare,Allocator>::begin() const
{
	return container_.begin();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::iterator
	sge::container::linear_set<T,Compare,Allocator>::end()
{
	return container_.end();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::const_iterator
	sge::container::linear_set<T,Compare,Allocator>::end() const
{
	return container_.end();
}

template<class T,class Compare,class Allocator>
bool sge::container::linear_set<T,Compare,Allocator>::empty() const
{
	return container_.empty();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::size_type
	sge::container::linear_set<T,Compare,Allocator>::size() const
{
	return container_.size();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::size_type
	sge::container::linear_set<T,Compare,Allocator>::max_size() const
{
	return container_.max_size();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::nonconst_iterator
	sge::container::linear_set<T,Compare,Allocator>::to_nonconst(iterator i)
{
	nonconst_iterator f = container_.begin();
	std::advance(f,std::distance(begin(),i));
	return f;
}

template<class T,class Compare,class Allocator>
std::pair<typename sge::container::linear_set<T,Compare,Allocator>::iterator,bool>
	sge::container::linear_set<T,Compare,Allocator>::insert(value_type const &v)
{
	iterator const f = lower_bound(v);
	if (f != container_.end() && !comp_(v,*f))
		return std::make_pair(f,false);
	return std::make_pair(container_.insert(to_nonconst(f),v),true);
}

// NOTE: iterator is a hint where to start the search
template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::iterator
	sge::container::linear_set<T,Compare,Allocator>::insert(iterator,value_type const &v)
{
	return insert(v).first;
}

template<class T,class Compare,class Allocator>
void sge::container::linear_set<T,Compare,Allocator>::erase(iterator const p)
{
	container_.erase(to_nonconst(p));
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::size_type
	sge::container::linear_set<T,Compare,Allocator>::erase(key_type const &k)
{
	iterator const f = find(k);
	if (f == end())
		return static_cast<size_type>(0);
	container_.erase(to_nonconst(f));
	return static_cast<size_type>(1);
}

template<class T,class Compare,class Allocator>
void sge::container::linear_set<T,Compare,Allocator>::erase(
	iterator const begin,
	iterator const last)
{
	container_.erase(to_nonconst(begin),to_nonconst(last));
}

template<class T,class Compare,class Allocator>
void sge::container::linear_set<T,Compare,Allocator>::swap(linear_set &r)
{
	container_.swap(r.container_);
	std::swap(comp_,r.comp_);
}

template<class T,class Compare,class Allocator>
void sge::container::linear_set<T,Compare,Allocator>::clear()
{
	container_.clear();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::key_compare
	sge::container::linear_set<T,Compare,Allocator>::key_comp() const
{
	return comp_;
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::value_compare
	sge::container::linear_set<T,Compare,Allocator>::value_comp() const
{
	return comp_;
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::iterator
	sge::container::linear_set<T,Compare,Allocator>::find(key_type const &k)
{
	iterator const it = lower_bound(k);
	if (it == end())
		return it;
	return !key_comp()(k,*it) ? it : end();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::const_iterator
	sge::container::linear_set<T,Compare,Allocator>::find(key_type const &k) const
{
	return const_cast<linear_set &>(*this).find(k);
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::size_type
	sge::container::linear_set<T,Compare,Allocator>::count(key_type const &k) const
{
	return find(k) == end() ? static_cast<size_type>(0) : static_cast<size_type>(1);
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::iterator
	sge::container::linear_set<T,Compare,Allocator>::lower_bound(key_type const &k) const
{
	for (iterator it = begin(); it != end(); ++it)
	{
		if (key_comp()(*it,k))
			continue;
		return it;
	}
	return end();
}

template<class T,class Compare,class Allocator>
typename sge::container::linear_set<T,Compare,Allocator>::iterator
	sge::container::linear_set<T,Compare,Allocator>::upper_bound(key_type const &k) const
{
	iterator i = lower_bound(k);
	if (!key_comp()(k,*i))
		return ++i;
	return i;
}

template<class T,class Compare,class Allocator>
std::pair<
	typename sge::container::linear_set<T,Compare,Allocator>::iterator,
	typename sge::container::linear_set<T,Compare,Allocator>::iterator>
	sge::container::linear_set<T,Compare,Allocator>::equal_range(key_type const &k) const
{
	return std::make_pair(lower_bound(k),upper_bound(k));
}

#endif
