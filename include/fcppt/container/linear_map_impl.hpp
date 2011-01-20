//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_LINEAR_MAP_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_LINEAR_MAP_IMPL_HPP_INCLUDED

#include <fcppt/container/linear_map.hpp>
// std::swap
#include <algorithm>
#include <utility>

template<class Key,class T,class Compare,class Allocator>
fcppt::container::linear_map<Key,T,Compare,Allocator>::value_compare::value_compare(Compare c)
	: comp(c) {}

template<class Key,class T,class Compare,class Allocator>
bool fcppt::container::linear_map<Key,T,Compare,Allocator>::value_compare::operator()(
	value_type const &x,
	value_type const &y) const
{
	return comp(x.first,y.first);
}

template<class Key,class T,class Compare,class Allocator>
fcppt::container::linear_map<Key,T,Compare,Allocator>::linear_map(
	Compare const &key_comp_,
	Allocator const &alloc_)
	: comp_(key_comp_),
	  container_(alloc_)
{
}

template<class Key,class T,class Compare,class Allocator>
fcppt::container::linear_map<Key,T,Compare,Allocator>::linear_map(
	linear_map const &lm)
	: comp_(lm.key_comp()),
	  container_(lm.container_)
{
}

template<class Key,class T,class Compare,class Allocator>
fcppt::container::linear_map<Key,T,Compare,Allocator> &
	fcppt::container::linear_map<Key,T,Compare,Allocator>::operator=(linear_map const &r)
{
	clear();
	insert(r.begin(),r.end());
	comp_ = r.comp_;
	return *this;
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::allocator_type get_allocator() const
{
	return container_.get_allocator();
}

template<class Key,class T,class Compare,class Allocator>
template<typename InputIterator>
fcppt::container::linear_map<Key,T,Compare,Allocator>::linear_map(
	InputIterator const begin,
	InputIterator const last,
	Compare const &key_comp_,
	Allocator const &alloc_)
	: comp_(key_comp_),
	  container_(alloc_)
{
	insert(begin,last);
}

template<class Key,class T,class Compare,class Allocator>
template<typename InputIterator>
void fcppt::container::linear_map<Key,T,Compare,Allocator>::insert(InputIterator it,InputIterator const last)
{
	for (;it != last; ++it)
		insert(*it);
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::reverse_iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::rbegin()
{
	return container_.rbegin();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::const_reverse_iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::rbegin() const
{
	return container_.rbegin();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::reverse_iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::rend()
{
	return container_.rend();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::const_reverse_iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::rend() const
{
	return container_.rend();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::begin()
{
	return container_.begin();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::const_iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::begin() const
{
	return container_.begin();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::end()
{
	return container_.end();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::const_iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::end() const
{
	return container_.end();
}

template<class Key,class T,class Compare,class Allocator>
bool fcppt::container::linear_map<Key,T,Compare,Allocator>::empty() const
{
	return container_.empty();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::size_type
	fcppt::container::linear_map<Key,T,Compare,Allocator>::size() const
{
	return container_.size();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::size_type
	fcppt::container::linear_map<Key,T,Compare,Allocator>::max_size() const
{
	return container_.max_size();
}

template<class Key,class T,class Compare,class Allocator>
T &fcppt::container::linear_map<Key,T,Compare,Allocator>::operator[](key_type const &k)
{
	return (*((insert(std::make_pair(k,T()))).first)).second;
}

template<class Key,class T,class Compare,class Allocator>
std::pair<typename fcppt::container::linear_map<Key,T,Compare,Allocator>::iterator,bool>
	fcppt::container::linear_map<Key,T,Compare,Allocator>::insert(value_type const &v)
{
	iterator const f = lower_bound(v.first);
	if (f != end() && !comp_(v,*f))
	{
		f->second = v.second;
		return std::make_pair(f,false);
	}
	return std::make_pair(container_.insert(f,v),true);
}

// NOTE: iterator is a hint where to start the search
template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::insert(iterator,value_type const &v)
{
	return insert(v);
}

template<class Key,class T,class Compare,class Allocator>
void fcppt::container::linear_map<Key,T,Compare,Allocator>::erase(iterator const p)
{
	container_.erase(p);
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::size_type
	fcppt::container::linear_map<Key,T,Compare,Allocator>::erase(key_type const &k)
{
	iterator const f = find(k);
	if (f == end())
		return static_cast<size_type>(0);
	container_.erase(f);
	return static_cast<size_type>(1);
}

template<class Key,class T,class Compare,class Allocator>
void fcppt::container::linear_map<Key,T,Compare,Allocator>::erase(
	iterator const begin,
	iterator const last)
{
	container_.erase(begin,last);
}

template<class Key,class T,class Compare,class Allocator>
void fcppt::container::linear_map<Key,T,Compare,Allocator>::swap(linear_map &r)
{
	container_.swap(r.container_);
	std::swap(comp_,r.comp_);
}

template<class Key,class T,class Compare,class Allocator>
void fcppt::container::linear_map<Key,T,Compare,Allocator>::clear()
{
	container_.clear();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::key_compare
	fcppt::container::linear_map<Key,T,Compare,Allocator>::key_comp() const
{
	return comp_.comp;
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::value_compare
	fcppt::container::linear_map<Key,T,Compare,Allocator>::value_comp() const
{
	return comp_;
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::find(key_type const &k)
{
	iterator const it = lower_bound(k);
	if (it == end())
		return it;
	return !key_comp()(k,it->first) ? it : end();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::const_iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::find(key_type const &k) const
{
	return const_cast<linear_map &>(*this).find(k);
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::size_type
	fcppt::container::linear_map<Key,T,Compare,Allocator>::count(key_type const &k) const
{
	return find(k) == end() ? static_cast<size_type>(0) : static_cast<size_type>(1);
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::lower_bound(key_type const &k)
{
	for (iterator it = begin(); it != end(); ++it)
	{
		if (key_comp()(it->first,k))
			continue;
		return it;
	}
	return end();
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::const_iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::lower_bound(key_type const &k) const
{
	return const_cast<linear_map &>(*this).lower_bound(k);
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::upper_bound(key_type const &k)
{
	iterator const i = lower_bound(k);
	if (!key_comp()(k,i->first))
		return ++i;
	return i;
}

template<class Key,class T,class Compare,class Allocator>
typename fcppt::container::linear_map<Key,T,Compare,Allocator>::const_iterator
	fcppt::container::linear_map<Key,T,Compare,Allocator>::upper_bound(key_type const &k) const
{
	return const_cast<linear_map &>(*this).upper_bound(k);
}

template<class Key,class T,class Compare,class Allocator>
std::pair<
	typename fcppt::container::linear_map<Key,T,Compare,Allocator>::iterator,
	typename fcppt::container::linear_map<Key,T,Compare,Allocator>::iterator>
	fcppt::container::linear_map<Key,T,Compare,Allocator>::equal_range(key_type const &k)
{
	return std::make_pair(lower_bound(k),upper_bound(k));
}

template<class Key,class T,class Compare,class Allocator>
std::pair<
	typename fcppt::container::linear_map<Key,T,Compare,Allocator>::const_iterator,
	typename fcppt::container::linear_map<Key,T,Compare,Allocator>::const_iterator>
	fcppt::container::linear_map<Key,T,Compare,Allocator>::equal_range(key_type const &k) const
{
	return std::make_pair(lower_bound(k),upper_bound(k));
}

#endif
