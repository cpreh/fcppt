//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/scoped_ptr_decl.hpp>
#include <fcppt/container/tree/is_ptr_value.hpp>
#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/mpl/inner.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/if.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{
/**
\brief A tree data structure
\ingroup fcpptcontainertree
\brief See the documentation of fcppt::container::tree::object to know more.
*/
template<
	typename T
>
class object
{
public:
	typedef boost::ptr_list<
		object
	> child_list;

	typedef std::unique_ptr<
		object
	> unique_ptr;

	// This is not child_list::value_type so T is easily accessible
	typedef T value_type;

	typedef typename child_list::size_type size_type;

	typedef typename child_list::difference_type difference_type;

	typedef typename child_list::reference reference;

	typedef typename child_list::const_reference const_reference;

	typedef typename child_list::iterator iterator;

	typedef typename child_list::const_iterator const_iterator;

	typedef typename child_list::reverse_iterator reverse_iterator;

	typedef typename child_list::const_reverse_iterator const_reverse_iterator;

	// support for ptr_tree

	typedef fcppt::container::tree::is_ptr_value<
		T
	> is_ptr_tree;

	/// The type to store, possibly extracted from <code>ptr_value<T></code>
	typedef typename boost::mpl::eval_if<
		is_ptr_tree,
		fcppt::mpl::inner<
			T
		>,
		boost::mpl::identity<
			T
		>
	>::type stored_type;

	/// The type to pass to other functions (either <code>stored_type const &</code> or <code>unique_ptr<stored_type> &&<T></code>)
	typedef typename boost::mpl::if_<
		is_ptr_tree,
		std::unique_ptr<
			stored_type
		> &&,
		stored_type const &
	>::type arg_type;

	/// The type that holds the stored type (either <code>T</code> or <code>scoped_ptr<T></code>)
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
	explicit
	object(
		arg_type
	);

	/**
	\brief Deeply copies a tree
	\see tree_copying
	*/
	object(
		object const &
	);

	/**
	\brief Deeply assigns a tree
	\see tree_copying
	*/
	object &
	operator=(
		object const &
	);

	~object();

	child_list &
	children();

	child_list const &
	children() const;

	/**
	\brief Returns a reference to the parent of this tree.

	If \link fcppt::container::tree::object::has_parent has_parent \endlink is false, behaviour is undefined.
	*/
	object &
	parent();

	/**
	\brief Returns a reference to the parent of this tree.

	If \link fcppt::container::tree::object::has_parent has_parent \endlink is false, behaviour is undefined.
	*/
	object const &
	parent() const;

	/**
	\brief Returns a pointer to the parent of this tree.

	If there is no parent, it returns 0.
	*/
	object *
	parent_ptr();

	/**
	\brief Returns a pointer to the parent of this tree.

	If there is no parent, it returns 0.
	*/
	object const *
	parent_ptr() const;

	/**
	\brief Returns if this tree has a parent.
	*/
	bool
	has_parent() const;

	/**
	\brief Sets a new parent
	*/
	void
	parent(
		object &
	);

	/**
	\brief Detaches the given child from the parent and returns it.
	*/
	unique_ptr
	release(
		iterator
	);

	/**
	\brief Returns an iterator pointing to the position in the parent's child container where this object resides.

	Behaviour is undefined if \link fcppt::container::tree::object::has_parent has_parent \endlink is false
	*/
	iterator
	child_position();

	/**
	\brief Returns an iterator pointing to the position in the parent's child container where this object resides.

	Behaviour is undefined if \link fcppt::container::tree::object::has_parent has_parent \endlink is false
	*/
	const_iterator
	child_position() const;

	/**
	\brief Sets a new value

	Depending on whether or not the tree has noncopyable semantics, this
	will either get a unique_ptr or <code>T</code> by value.
	*/
	void
	value(
		arg_type
	);

	/**
	\brief Retrieves the tree's value
	*/
	stored_type &
	value();

	/**
	\brief Retrieves the tree's value
	*/
	stored_type const &
	value() const;

	/**
	\brief Returns if this node holds a value
	Will always be true for normal trees.
	If the tree holds a ptr_value it depends on whether it has been initialized
	*/
	bool
	has_value() const;

	/**
	\brief Returns a reference to the holder type

	This can be used to release the scoped_ptr if the tree has noncopyable semantics.

	\see fcppt::container::tree::release
	*/
	holder_type &
	holder();

	/**
	\brief Returns a const reference to the holder type
	*/
	holder_type const &
	holder() const;

	/**
	\brief Inserts a new child at the end of the child list
	*/
	void
	push_back(
		unique_ptr
	);

	/**
	\brief Inserts a new child at the end of the child list
	*/
	void
	push_back(
		arg_type
	);

	/**
	\brief Removes a child from the end of the child list
	*/
	void
	pop_back();

	/**
	\brief Adds a child in front of the child list
	*/
	void
	push_front(
		unique_ptr
	);

	/**
	\brief Adds a child in front of the child list
	*/
	void
	push_front(
		arg_type
	);

	/**
	\brief Removes a child from the front of the child list
	*/
	void
	pop_front();

	/**
	\brief Removes all children
	*/
	void
	clear();

	/**
	\brief Returns a reference to the last child.

	Behaviour is undefined if \link fcppt::container::tree::object::empty empty \endlink is true.
	*/
	reference
	back();

	/**
	\brief Returns a reference to the last child.

	Behaviour is undefined if \link fcppt::container::tree::object::empty empty \endlink is true.
	*/
	const_reference
	back() const;

	/**
	\brief Returns a reference to the first child.

	Behaviour is undefined if \link fcppt::container::tree::object::empty empty \endlink is true.
	*/
	reference
	front();

	/**
	\brief Returns a reference to the first child.

	Behaviour is undefined if \link fcppt::container::tree::object::empty empty \endlink is true.
	*/
	const_reference
	front() const;

	/**
	\brief Returns an iterator to the first child (if present)
	*/
	iterator
	begin();

	/**
	\brief Returns an iterator to "one past the last child", if present, otherwise returns \link fcppt::container::tree::object::begin begin \endlink
	*/
	iterator
	end();

	/**
	\brief Returns an iterator to the first child (if present)
	*/
	const_iterator
	begin() const;

	/**
	\brief Returns an iterator to "one past the last child", if present, otherwise returns \link fcppt::container::tree::object::begin begin \endlink
	*/
	const_iterator
	end() const;

	/**
	\brief Returns a reverse_iterator to the last element (if present)
	*/
	reverse_iterator
	rbegin();

	/**
	\brief Returns a reverse_iterator to the first element (if present)
	*/
	reverse_iterator
	rend();

	/**
	\brief Returns a const_reverse_iterator to the last element (if present)
	*/
	const_reverse_iterator
	rbegin() const;

	/**
	\brief Returns a const_reverse_iterator to the first element (if present)
	*/
	const_reverse_iterator
	rend() const;

	/**
	\brief Returns a const_iterator to the first child (if present)
	*/
	const_iterator
	cbegin() const;

	/**
	\brief Returns a const_iterator to the first child (if present)
	*/
	const_iterator
	cend() const;

	/**
	\brief Returns a const_reverse_iterator to the last element (if present)
	*/
	const_reverse_iterator
	crbegin() const;

	/**
	\brief Returns a const_reverse_iterator to the first element (if present)
	*/
	const_reverse_iterator
	crend() const;

	/**
	\brief Inserts an element before the given iterator
	*/
	void
	insert(
		iterator,
		unique_ptr
	);

	/**
	\brief Inserts an element before the given iterator
	*/
	void
	insert(
		iterator,
		arg_type
	);

	/**
	\brief Erases a single element
	*/
	void
	erase(
		iterator
	);

	/**
	\brief Erases a range
	*/
	void
	erase(
		iterator,
		iterator
	);

	/**
	\brief Returns the number of children

	The complexity of this is O(n)
	*/
	size_type
	size() const;

	/**
	\brief Returns the ptr_list's max_size
	*/
	size_type
	max_size() const;

	/**
	\brief Returns if the container is empty
	*/
	bool
	empty() const;

	/**
	\brief Swaps with another tree
	*/
	void
	swap(
		object &
	);
private:
	holder_type value_;

	object *parent_;

	child_list children_;
};

/**
\brief Compares the values and the children

This is equal to <code>a.value() == b.value() && a.children() == b.children()</code>
*/
template<
	typename T
>
bool
operator==(
	fcppt::container::tree::object<T> const &,
	fcppt::container::tree::object<T> const &
);

/**
\brief Compares the values and the children

This is equal to <code>a.value() != b.value() || a.children() != b.children()</code>
*/
template<
	typename T
>
bool
operator!=(
	fcppt::container::tree::object<T> const &,
	fcppt::container::tree::object<T> const &
);

/**
\brief Swaps two trees
*/
template<
	typename T
>
void
swap(
	fcppt::container::tree::object<T> &,
	fcppt::container::tree::object<T> &
);

}
}
}

#endif
