//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_LINEAR_MAP_HPP_INCLUDED
#define FCPPT_CONTAINER_LINEAR_MAP_HPP_INCLUDED

// std::less
#include <functional>
// std::allocator
#include <memory>
// std::list
#include <list>
// std::pair
#include <utility>

namespace fcppt
{
namespace container
{

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key,T> > >
class linear_map
{
	public:
	typedef Key                                      key_type;
	typedef T                                        mapped_type;
	typedef std::pair<const Key,T>                   value_type;
	typedef Compare                                  key_compare;
	typedef Allocator                                allocator_type;
	typedef typename Allocator::reference            reference;
	typedef typename Allocator::const_reference      const_reference;
	typedef std::list<value_type>                    container_type;
	typedef typename container_type::iterator        iterator;
	typedef typename container_type::const_iterator  const_iterator;
	typedef typename container_type::size_type       size_type;
	typedef typename container_type::difference_type difference_type;
	typedef typename Allocator::pointer              pointer;
	typedef typename Allocator::const_pointer        const_pointer;

	typedef typename container_type::reverse_iterator reverse_iterator;
	typedef typename container_type::const_reverse_iterator const_reverse_iterator;

	class value_compare
		: public std::binary_function<value_type,value_type,bool>
	{
		friend class linear_map;
		private:
		Compare comp;
		value_compare(Compare);
		public:
		bool operator()(value_type const &x,value_type const &y) const;
	};

	explicit linear_map(Compare const & = Compare(),Allocator const & = Allocator());
	template<class InputIterator>
	linear_map(InputIterator begin,InputIterator last,Compare const & = Compare(),Allocator const & = Allocator());
	linear_map(linear_map const &);

	linear_map &operator=(linear_map const &);

	allocator_type get_allocator() const;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;

	bool empty() const;
	size_type size() const;
	size_type max_size() const;
	T& operator[](key_type const &);

	std::pair<iterator,bool> insert(value_type const &);
	iterator insert(iterator position,value_type const &);
	template<class InputIterator>
	void insert(InputIterator begin,InputIterator last);

	void erase(iterator position);
	size_type erase(key_type const &);
	void erase(iterator begin,iterator last);
	void swap(linear_map &);
	void clear();

	key_compare key_comp() const;
	value_compare value_comp() const;

	iterator find(key_type const &);
	const_iterator find(key_type const &) const;
	size_type count(key_type const &) const;

	iterator lower_bound(key_type const &);
	const_iterator lower_bound(key_type const &) const;
	iterator upper_bound(key_type const &);
	const_iterator upper_bound(key_type const &) const;

	std::pair<iterator,iterator> equal_range(key_type const &);
	std::pair<const_iterator,const_iterator> equal_range(key_type const &) const;
	private:
	value_compare comp_;
	container_type container_;
};

template<class Key,class T,class Compare,class Allocator>
bool operator==(linear_map<Key,T,Compare,Allocator> const &,linear_map<Key,T,Compare,Allocator> const &);

template<class Key,class T,class Compare,class Allocator>
bool operator!=(linear_map<Key,T,Compare,Allocator> const &,linear_map<Key,T,Compare,Allocator> const &);

template<class Key,class T,class Compare,class Allocator>
bool operator<(linear_map<Key,T,Compare,Allocator> const &,linear_map<Key,T,Compare,Allocator> const &);

template<class Key,class T,class Compare,class Allocator>
bool operator>(linear_map<Key,T,Compare,Allocator> const &,linear_map<Key,T,Compare,Allocator> const &);

template<class Key,class T,class Compare,class Allocator>
bool operator>=(linear_map<Key,T,Compare,Allocator> const &,linear_map<Key,T,Compare,Allocator> const &);

template<class Key,class T,class Compare,class Allocator>
bool operator<=(linear_map<Key,T,Compare,Allocator> const &,linear_map<Key,T,Compare,Allocator> const &);

template<class Key,class T,class Compare,class Allocator>
void swap(linear_map<Key,T,Compare,Allocator> &,linear_map<Key,T,Compare,Allocator> &);

}
}

#endif
