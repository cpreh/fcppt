//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/scoped_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/tree/is_ptr_value.hpp>
#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/mpl/inner.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/if.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
/// Contains fcppt::container::tree::object and helper types/functions for it.
namespace tree
{
/**
\defgroup fcpptcontainertree fcppt::container::tree
\ingroup fcpptcontainer
\brief See the documentation of fcppt::container::tree::object to know more.
*/

/**
\brief A tree data structure
\ingroup fcpptcontainertree

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref tree_introduction</li>
	<li>\ref tree_traversals</li>
	<li>\ref tree_noncopyable</li>
	<li>\ref tree_copying</li>
</ol>

</td>
</tr>
</table>

\section tree_introduction Introduction
An fcppt::container::tree::object<T> is a container modeling an n-ary tree
holding objects of type <code>T</code>. It has a value of type
<code>T</code> and children of type fcppt::container::tree::object<T>.

\note
Because of the inherent recursive property of the tree, it has to store its
children in a <a
href="http://www.boost.org/doc/libs/1_48_0/libs/ptr_container/doc/ptr_list.html">boost::ptr_list</a>
which might make tree a bit heavy to include.  Consider using forward
declarations where possible.

The tree tries to mimic the sequence containers from the standard library. Also,
its implementation is "minimal" in the sense that everything but trivial
operations are outsourced to external headers - the pre order traversal
is an example of this. Most of the operations are self-explanatory.
Here is a small example of the tree:

\snippet container/tree_simple.cpp main

Note also that all operations which implicitly depend on a parent being
present are undefined if \link fcppt::container::tree::object::has_parent
has_parent \endlink returns false. The same goes for all operations which
depend on at least one child being present and \link
fcppt::container::tree::object::empty empty \endlink returning true.

\section tree_traversals Iterators/Traversals

The tree uses a <a
href="http://www.boost.org/doc/libs/1_48_0/libs/ptr_container/doc/ptr_list.html">boost::ptr_list</a>
to store its children, so the iterator guarantees are the same as for this
container. Apart from using the traditional iteration methods &ndash; using
\link fcppt::container::tree::object::begin begin \endlink, \link
fcppt::container::tree::object::end end \endlink, \link
fcppt::container::tree::object::rbegin rbegin \endlink, \link
fcppt::container::tree::object::rend rend \endlink
&ndash; there are external traversal classes. Those are best explained using
a little example:

\snippet container/tree_traversal.cpp main

Aside from \link fcppt::container::tree::pre_order pre_order \endlink, no
other traversals are implemented as of yet.

\section tree_noncopyable Non-copyable semantics

We already mentioned <a
href="http://www.boost.org/doc/libs/1_48_0/libs/ptr_container/doc/ptr_list.html">boost::ptr_list</a>,
which is designed to store values by pointer and to have ownership at the
same time.

This is useful for values that cannot be copied, for example.
<code>fcppt::container::tree::object</code> also supports storing non-copyable values
(and taking ownership of them). Instead of writing

\code
fcppt::container::tree::object<T>
\endcode

you can say

\code
fcppt::container::tree::object
<
	fcppt::container::tree::ptr_value<T>
>
\endcode

which turns the tree into a ptr_container. A <code>tree::object<ptr_value<T>
></code> will have the following changes from a normal tree:

<ul>
	<li>All arguments of values it expects are <code>fcppt::unique_ptr<T></code> (see \ref insert_link_to_unique_ptr_introduction_here)</li>
	<li>The internal type is an <code>fcppt::scoped_ptr<T></code> (see \ref insert_link_to_scoped_ptr_here)</li>
</ul>

It is also possible to release the held <code>scoped_ptr</code> with fcppt::container::tree::release.

\section tree_copying Copying

Every tree can be deeply copied by invoking its copy constructor or assignment
operator. However, for a tree with noncopyable semantics, the situation isn't as easy. To still provide deep copying in this
case, there is a function called \link fcppt::container::tree::copy_tree_value
copy_tree_value \endlink which the tree will invoke via argument dependant
lookup. For a <code>tree::%object<tree::ptr_value<T>></code> the signature must be

\code
fcppt::unique_ptr<T> copy_tree_value(T const &);
\endcode

The default behaviour is to invoke the copy constructor of <code>T</code> which will only
work if <code>T</code> is copyable itself.
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

	typedef fcppt::unique_ptr<
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

	typedef tree::is_ptr_value<
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

	/// The type to forward to other functions (either <code>T</code> or <code>unique_ptr<T></code>)
	typedef typename boost::mpl::if_<
		is_ptr_tree,
		fcppt::unique_ptr<
			stored_type
		>,
		stored_type
	>::type arg_base_type;

	/// The type to pass to other functions (either <code>T const &</code> or <code>unique_ptr<T></code>)
	typedef typename boost::mpl::if_<
		is_ptr_tree,
		arg_base_type,
		arg_base_type const &
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
	explicit object(
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

	This can be used to release the the scoped_ptr if the tree has noncopyable semantics.

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
	object<T> const &,
	object<T> const &
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
	object<T> const &,
	object<T> const &
);

/**
\brief Swaps two trees
*/
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

#endif
