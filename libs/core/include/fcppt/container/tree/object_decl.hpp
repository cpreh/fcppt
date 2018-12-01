//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/optional/object_decl.hpp>
#include <fcppt/optional/reference.hpp>
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
	fcppt::optional::reference<
		object
	>
	optional_ref;

	typedef
	fcppt::optional::reference<
		object const
	>
	const_optional_ref;

	typedef
	fcppt::optional::object<
		object
	>
	optional_object;

	typedef
	fcppt::reference<
		object
	>
	reference;

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
	)
	noexcept(
		std::is_nothrow_move_assignable<
			T
		>::value
	);

	~object();

	child_list const &
	children() const;

	/**
	\brief Returns a reference to the parent of this tree.
	*/
	optional_ref
	parent();

	/**
	\brief Returns a reference to the parent of this tree.
	*/
	const_optional_ref
	parent() const;

	/**
	\brief Detaches the given child from the parent and returns it.
	*/
	object
	release(
		iterator
	);

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
	reference
	push_back(
		object &&
	);

	/**
	\brief Inserts a new child at the end of the child list
	*/
	reference
	push_back(
		T const &
	);

	reference
	push_back(
		T &&
	);

	/**
	\brief Removes a child from the end of the child list
	*/
	optional_object
	pop_back();

	/**
	\brief Adds a child in front of the child list
	*/
	reference
	push_front(
		object &&
	);

	/**
	\brief Adds a child in front of the child list
	*/
	reference
	push_front(
		T const &
	);

	reference
	push_front(
		T &&
	);

	/**
	\brief Removes a child from the front of the children list and returns it.
	*/
	optional_object
	pop_front();

	/**
	\brief Removes all children
	*/
	void
	clear();

	optional_ref
	back();

	const_optional_ref
	back() const;

	optional_ref
	front();

	const_optional_ref
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
	*/
	size_type
	size() const;

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
	child_list
	copy_children(
		child_list const &
	);

	child_list
	move_children(
		child_list &&
	);

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
