//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/container/tree/is_ptr_value.hpp>
#include <fcppt/mpl/inner.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/if.hpp>
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

	typedef typename child_list::value_type value_type;

	typedef typename child_list::size_type size_type;

	typedef typename child_list::difference_type difference_type;

	typedef typename child_list::reference reference;

	typedef typename child_list::const_reference const_reference;

	typedef typename child_list::iterator iterator;

	typedef typename child_list::const_iterator const_iterator;

	typedef typename child_list::reverse_iterator reverse_iterator;

	typedef typename child_list::const_reverse_iterator const_reverse_iterator;

	// support for ptr_tree
	
	typedef tree::is_ptr_value<
		T
	> is_ptr_tree;

	/// The type to store, possibly extracted from ptr_value<T>
	typedef typename boost::mpl::eval_if<
		is_ptr_tree,
		fcppt::mpl::inner<
			T
		>,
		boost::mpl::identity<
			T
		>
	>::type stored_type;

	/// The type to forward to other functions (either T or unique_ptr<T>)
	typedef typename boost::mpl::if_<
		is_ptr_tree,
		fcppt::unique_ptr<
			stored_type
		>,
		stored_type
	>::type arg_base_type;

	/// The type to pass to other functions (either T const & or unique_ptr<T>)
	typedef typename boost::mpl::if_<
		is_ptr_tree,
		arg_base_type,
		arg_base_type const &
	>::type arg_type;

	/// The type that holds the stored type (either T or scoped_ptr<T>)
	typedef typename boost::mpl::if_<
		is_ptr_tree,
		fcppt::scoped_ptr<
			stored_type
		>,
		stored_type
	>::type holder_type;

	/// Constructs the tree using the default constructed value 
	object();

	/// Constructs the object using the given value
	explicit object(
		arg_type
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
	unique_ptr
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
		arg_type
	);

	stored_type &
	value();

	stored_type const &
	value() const;

	/// Returns if this node holds a value
	/**
	 * Will always be true for normal trees.
	 * If the tree holds a ptr_value it depends on whether it has been initialized
	*/
	bool
	has_value() const;

	/// Can be used to release the scoped_ptr
	holder_type &
	holder();

	holder_type const &
	holder() const;

	void
	push_back(
		unique_ptr
	);

	void
	push_back(
		arg_type
	);

	void
	pop_back();

	void
	push_front(
		unique_ptr
	);

	void
	push_front(
		arg_type
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
		unique_ptr
	);

	/// Inserts an element before the given iterator
	void
	insert(
		iterator,
		arg_type
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
	holder_type value_;

	object *parent_;

	child_list children_;
//->
};

/// Compares the values and the children
/**
 * equal to a.value() == b.value() && a.children() == b.children()
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
