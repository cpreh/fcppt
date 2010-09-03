//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/unique_ptr.hpp>
#include <boost/ptr_container/ptr_list.hpp>

//[tree
namespace fcppt
{
namespace container
{
namespace tree
{

template<
	typename T
>
class object
{
public:
	typedef boost::ptr_list<
		object	
	> child_list;

	typedef fcppt::unique_ptr<
		object	
	> unique_ptr;

	typedef unique_ptr auto_ptr; // legacy typedef

	typedef typename child_list::value_type value_type;
	typedef typename child_list::size_type size_type;
	typedef typename child_list::difference_type difference_type;
	typedef typename child_list::reference reference;
	typedef typename child_list::const_reference const_reference;
	typedef typename child_list::iterator iterator;
	typedef typename child_list::const_iterator const_iterator;
	typedef typename child_list::reverse_iterator reverse_iterator;
	typedef typename child_list::const_reverse_iterator const_reverse_iterator;

	/// Constructs the tree using the default constructed value 
	object();

	/// Constructs the object using the given value
	explicit object(
		T const &
	);

	~object();

	child_list &
	children();

	child_list const &
	children() const;

	/// Returns a reference to the parent of this tree. If has_parent() is false, behaviour is undefined.
	object &
	parent();

	/// Returns a reference to the parent of this tree. If has_parent() is false, behaviour is undefined.
	object const &
	parent() const;

	/// Returns &(parent()) if has_parent() is true, else returns 0
	object *
	parent_ptr();

	/// Returns &(parent()) if has_parent() is true, else returns 0
	object const *
	parent_ptr() const;

	bool
	has_parent() const;

	void
	parent(
		object &
	);

	/// Detaches the given child from the parent and returns it.
	auto_ptr
	release(
		iterator
	);

	/// Returns an iterator pointing to the position in the parent's child container where this object resides. Behaviour is undefined if has_parent() is false
	iterator
	child_position();

	/// Returns an iterator pointing to the position in the parent's child container where this object resides. Behaviour is undefined if has_parent() is false
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

	/// Returns a reference to the last child. Undefined if empty() is true.
	reference
	back();

	/// Returns a reference to the last child. Undefined if empty() is true.
	const_reference
	back() const;

	/// Returns a reference to the first child. Undefined if empty() is true.
	reference
	front();

	/// Returns a reference to the first child. Undefined if empty() is true.
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

	const_iterator
	cbegin() const;

	const_iterator
	cend() const;

	const_reverse_iterator
	crbegin() const;

	const_reverse_iterator
	crend() const;

	/// Inserts an element before the given iterator
	void
	insert(
		iterator,
		auto_ptr
	);

	/// Inserts an element before the given iterator
	void
	insert(
		iterator,
		T const &
	);

	/// Erases a single element
	void
	erase(
		iterator
	);

	/// Erases a range
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

	void
	swap(
		object &
	);
//<-
private:
	T value_;
	object *parent_;
	child_list children_;
//->
};

/// Compares the values and the children
/** equal to a.value() == b.value() && a.children() == b.children()
*/
template<
	typename T
>
bool
operator==(
	object<T> const &,
	object<T> const &
);

template<
	typename T
>
bool
operator!=(
	object<T> const &,
	object<T> const &
);

template<
	typename T
>
void
swap(
	object<T> &,
	object<T> &
);

}
}
}
//]

#endif
