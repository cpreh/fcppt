//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/container/tree/optional_ref_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <list>
#include <type_traits>
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
*/
template<
	typename T
>
class object
{
public:
	typedef
	std::list<
		object
	>
	child_list;

	typedef
	T
	value_type;

	typedef
	typename
	child_list::size_type
	size_type;

	typedef
	typename
	child_list::difference_type
	difference_type;

	typedef object &reference;

	typedef object const &const_reference;

	typedef
	typename
	child_list::iterator
	iterator;

	typedef
	typename
	child_list::const_iterator
	const_iterator;

	typedef
	typename
	child_list::reverse_iterator
	reverse_iterator;

	typedef
	typename
	child_list::const_reverse_iterator
	const_reverse_iterator;

	typedef
	fcppt::container::tree::optional_ref<
		object
	>
	optional_ref;

	typedef
	fcppt::container::tree::optional_ref<
		object const
	>
	const_optional_ref;

	/// Constructs the tree using the default constructed value
	object();

	/// Constructs the object using the given value
	explicit
	object(
		T const &
	);

	explicit
	object(
		T &&
	);

	/**
	\brief Constructs a tree, including its children, by moving
	*/
	object(
		T &&,
		child_list &&
	);

	/**
	\brief Deeply copies a tree

	\see tree_copying
	*/
	object(
		object const &
	);

	object(
		object &&
	)
	noexcept(
		std::is_nothrow_move_constructible<
			T
		>::value
	);

	/**
	\brief Deeply assigns a tree

	\see tree_copying
	*/
	object &
	operator=(
		object const &
	);

	object &
	operator=(
		object &&
	);

	~object();

	child_list &
	children();

	child_list const &
	children() const;

	/**
	\brief Returns a reference to the parent of this tree.
	*/
	optional_ref const
	parent();

	/**
	\brief Returns a reference to the parent of this tree.
	*/
	const_optional_ref const
	parent() const;

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
		optional_ref const &
	);

	/**
	\brief Detaches the given child from the parent and returns it.
	*/
	object
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
	*/
	void
	value(
		T const &
	);

	void
	value(
		T &&
	);

	/**
	\brief Retrieves the tree's value
	*/
	T &
	value();

	/**
	\brief Retrieves the tree's value
	*/
	T const &
	value() const;

	/**
	\brief Inserts a new child at the end of the child list
	*/
	void
	push_back(
		object &&
	);

	/**
	\brief Inserts a new child at the end of the child list
	*/
	void
	push_back(
		T const &
	);

	void
	push_back(
		T &&
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
		object &&
	);

	/**
	\brief Adds a child in front of the child list
	*/
	void
	push_front(
		T const &
	);

	void
	push_front(
		T &&
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
		object &&
	);

	/**
	\brief Inserts an element before the given iterator
	*/
	void
	insert(
		iterator,
		T const &
	);

	void
	insert(
		iterator,
		T &&
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
	\brief Returns the list's max_size
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

	/**
	\brief Sorts the children using operator< on T
	*/
	void
	sort();

	/**
	\brief Sorts the children using a predicate on two Ts
	*/
	template<
		typename Predicate
	>
	void
	sort(
		Predicate const &
	);
private:
	T value_;

	optional_ref parent_;

	child_list children_;
};

/**
\brief Swaps two trees
*/
template<
	typename T
>
void
swap(
	fcppt::container::tree::object<
		T
	> &,
	fcppt::container::tree::object<
		T
	> &
);

}
}
}

#endif
