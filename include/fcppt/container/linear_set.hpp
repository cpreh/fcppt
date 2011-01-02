//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_LINEAR_SET_HPP_INCLUDED
#define FCPPT_CONTAINER_LINEAR_SET_HPP_INCLUDED

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
	class Compare = std::less<Key>,
	class Allocator = std::allocator<Key> >
class linear_set
{
	public:
	typedef Key                                      key_type;
	typedef Key                                      value_type;
	typedef Compare                                  key_compare;
	typedef Compare                                  value_compare;
	typedef Allocator                                allocator_type;
	typedef typename Allocator::reference            reference;
	typedef typename Allocator::const_reference      const_reference;
	typedef std::list<value_type>                    container_type;
	typedef typename container_type::const_iterator  iterator;
	typedef typename container_type::const_iterator  const_iterator;
	typedef typename container_type::size_type       size_type;
	typedef typename container_type::difference_type difference_type;
	typedef typename Allocator::pointer              pointer;
	typedef typename Allocator::const_pointer        const_pointer;

	typedef typename container_type::reverse_iterator reverse_iterator;
	typedef typename container_type::const_reverse_iterator const_reverse_iterator;

	explicit linear_set(Compare const & = Compare(),Allocator const & = Allocator());
	template<class InputIterator>
	linear_set(InputIterator begin,InputIterator last,Compare const & = Compare(),Allocator const & = Allocator());
	linear_set(linear_set const &);

	linear_set &operator=(linear_set const &);

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

	std::pair<iterator,bool> insert(value_type const &);
	iterator insert(iterator position,value_type const &);
	template<class InputIterator>
	void insert(InputIterator begin,InputIterator last);

	void erase(iterator position);
	size_type erase(key_type const &);
	void erase(iterator begin,iterator last);
	void swap(linear_set &);
	void clear();

	key_compare key_comp() const;
	value_compare value_comp() const;

	iterator find(key_type const &);
	const_iterator find(key_type const &) const;
	size_type count(key_type const &) const;

	iterator lower_bound(key_type const &) const;
	iterator upper_bound(key_type const &) const;

	std::pair<iterator,iterator> equal_range(key_type const &) const;
	private:
	value_compare comp_;
	container_type container_;

	typedef typename container_type::iterator nonconst_iterator;
	nonconst_iterator to_nonconst(iterator);
};

template<class T,class Compare,class Allocator>
bool operator==(linear_set<T,Compare,Allocator> const &,linear_set<T,Compare,Allocator> const &);

template<class T,class Compare,class Allocator>
bool operator!=(linear_set<T,Compare,Allocator> const &,linear_set<T,Compare,Allocator> const &);

template<class T,class Compare,class Allocator>
bool operator<(linear_set<T,Compare,Allocator> const &,linear_set<T,Compare,Allocator> const &);

template<class T,class Compare,class Allocator>
bool operator>(linear_set<T,Compare,Allocator> const &,linear_set<T,Compare,Allocator> const &);

template<class T,class Compare,class Allocator>
bool operator>=(linear_set<T,Compare,Allocator> const &,linear_set<T,Compare,Allocator> const &);

template<class T,class Compare,class Allocator>
bool operator<=(linear_set<T,Compare,Allocator> const &,linear_set<T,Compare,Allocator> const &);

template<class T,class Compare,class Allocator>
void swap(linear_set<T,Compare,Allocator> &,linear_set<T,Compare,Allocator> &);

}
}

#endif
