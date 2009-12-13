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


#ifndef SGE_CONTAINER_TREE_DECL_HPP_INCLUDED
#define SGE_CONTAINER_TREE_DECL_HPP_INCLUDED

#include <sge/container/tree_fwd.hpp>
#include <sge/auto_ptr.hpp>
#include <boost/ptr_container/ptr_list.hpp>

namespace sge
{
namespace container
{

template<
	typename T
> class init_tree;

template<
	typename T
>
class tree {
public:
	typedef boost::ptr_list<
		tree
	> child_list;

	typedef sge::auto_ptr<
		tree
	> auto_ptr;

	typedef typename child_list::value_type value_type;
	typedef typename child_list::size_type size_type;
	typedef typename child_list::difference_type difference_type;
	typedef typename child_list::reference reference;
	typedef typename child_list::const_reference const_reference;
	typedef typename child_list::iterator iterator;
	typedef typename child_list::const_iterator const_iterator;
	typedef typename child_list::reverse_iterator reverse_iterator;
	typedef typename child_list::const_reverse_iterator const_reverse_iterator;

	tree();

	explicit tree(
		init_tree<T> const &
	);

	explicit tree(
		T const &
	);

	~tree();

	child_list &
	children();

	child_list const &
	children() const;

	tree &
	parent();

	tree const &
	parent() const;

	tree *
	parent_ptr();

	tree const *
	parent_ptr() const;

	bool
	has_parent() const;

	void
	parent(
		tree &
	);

	void
	orphan();

	auto_ptr
	release(
		iterator
	);

	iterator
	child_position();

	const_iterator
	child_position() const;

	void
	value(
		T const &
	);

	T &
	value();

	T const &
	value() const;

	void
	push_back(
		auto_ptr
	);

	void
	push_back(
		T const &
	);

	void
	pop_back();

	void
	push_front(
		auto_ptr
	);

	void
	push_front(
		T const &
	);

	void
	pop_front();

	void
	clear();

	reference
	back();

	const_reference
	back() const;

	reference
	front();

	const_reference
	front() const;

	iterator
	begin();

	iterator
	end();

	const_iterator
	begin() const;

	const_iterator
	end() const;

	reverse_iterator
	rbegin();

	reverse_iterator
	rend();

	const_reverse_iterator
	rbegin() const;

	const_reverse_iterator
	rend() const;

	void
	insert(
		iterator,
		auto_ptr
	);

	void
	insert(
		iterator,
		T const &
	);

	void
	erase(
		iterator
	);

	void
	erase(
		iterator,
		iterator
	);

	size_type
	size() const;

	size_type
	max_size() const;

	bool
	empty() const;
private:
	T value_;
	tree *parent_;
	child_list children_;
};

template<
	typename T
>
bool
operator==(
	tree<T> const &,
	tree<T> const &
);

template<
	typename T
>
bool
operator!=(
	tree<T> const &,
	tree<T> const &
);

}
}

#endif
