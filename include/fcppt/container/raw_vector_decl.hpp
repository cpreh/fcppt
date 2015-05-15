//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_RAW_VECTOR_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/container/raw_vector_fwd.hpp>
#include <fcppt/type_traits/is_input_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{

/**
\brief A special vector class for pod types

\ingroup fcpptcontainerraw_vector

\tparam T Container's <code>value_type</code>. Has to be a POD type; see <a
href="http://www.boost.org/doc/libs/1_40_0/libs/type_traits/doc/html/boost_typetraits/reference/is_pod.html">here</a>
for what this means.

\tparam A The allocator.

See the \link fcpptcontainerraw_vector module documentation \endlink for more
information.
*/
template<
	typename T,
	typename A
>
class raw_vector
{
	static_assert(
		std::is_pod<
			T
		>::value,
		"raw_vector can only deal with PODs"
	);
public:
	/**
	\brief A type that represents the data type stored in a vector.
	*/
	typedef T                                     value_type;
	/**
	\brief A type that represents the allocator class for the vector object.
	*/
	typedef A                                     allocator_type;
	/**
	\brief A type that counts the number of elements in a vector.
	*/
	typedef typename A::size_type                 size_type;
	/**
	\brief A type that provides the difference between the addresses of two elements in a vector.
	*/
	typedef typename A::difference_type           difference_type;
	/**
	\brief A type that provides a pointer to an element in a vector.
	*/
	typedef typename A::pointer                   pointer;
	/**
	\brief A type that provides a pointer to a <code>const</code> element in a vector.
	*/
	typedef typename A::const_pointer             const_pointer;
	/**
	\brief A type that provides a reference to an element stored in a vector.
	*/
	typedef typename A::reference                 reference;
	/**
	\brief A type that provides a reference to a <code>const</code> element stored in a vector for reading and performing <code>const</code> operations.
	*/
	typedef typename A::const_reference           const_reference;
	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a vector.
	*/
	typedef pointer                               iterator;
	/**
	\brief A type that provides a random-access iterator that can read a <code>const</code> element in a vector.
	*/
	typedef const_pointer                         const_iterator;
	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a reversed vector.
	*/
	typedef std::reverse_iterator<iterator>       reverse_iterator;
	/**
	\brief A type that provides a random-access iterator that can read any <code>const</code> element in the vector.
	*/
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	/**
	\brief Returns a random-access iterator to the first element in the container.
	*/
	iterator
	begin();

	/**
	\brief Returns a random-access iterator to the first element in the container.
	*/
	const_iterator
	begin() const;

	/**
	\brief Returns a random-access iterator that points just beyond the end of the vector.
	*/
	iterator
	end();

	/**
	\brief Returns a random-access iterator that points just beyond the end of the vector.
	*/
	const_iterator
	end() const;

	/**
	\brief Returns an iterator to the first element in a reversed vector.
	*/
	reverse_iterator
	rbegin();

	/**
	\brief Returns an iterator to the first element in a reversed vector.
	*/
	const_reverse_iterator
	rbegin() const;

	/**
	\brief Returns an iterator to the end of a reversed vector.
	*/
	reverse_iterator
	rend();

	/**
	\brief Returns an iterator to the end of a reversed vector.
	*/
	const_reverse_iterator
	rend() const;

	/**
	\brief Returns a random-access const-iterator to the first element in the container.
	\note
	This function is not found in (C++03's) <code>std::vector</code>
	*/
	const_iterator
	cbegin() const;

	/**
	\brief Returns a random-access const-iterator that points just beyond the end of the vector.
	\note
	This function is not found in (C++03's) <code>std::vector</code>
	*/
	const_iterator
	cend() const;

	/**
	\brief Returns a const-iterator to the first element in a reversed vector.
	\note
	This function is not found in (C++03's) <code>std::vector</code>
	*/
	const_reverse_iterator
	crbegin() const;

	/**
	\brief Returns an iterator to the end of a reversed vector.
	\note
	This function is not found in (C++03's) <code>std::vector</code>
	*/
	const_reverse_iterator
	crend() const;

	/**
	\brief Returns a reference to the vector element at a specified position.
	*/
	reference
	operator[](
		size_type
	);

	/**
	\brief Returns a reference to the vector element at a specified position.
	*/
	const_reference
	operator[](
		size_type
	) const;

	/**
	\brief Returns a reference to the element at a specified location in the vector.
	\throws fcppt::container::out_of_range
	*/
	reference
	at(
		size_type
	);

	/**
	\brief Returns a reference to the element at a specified location in the vector.
	\throws fcppt::container::out_of_range
	*/
	const_reference
	at(
		size_type
	) const;

	/**
	\brief Returns a reference to the first element in a vector.
	*/
	reference
	front();

	/**
	\brief Returns a reference to the first element in a vector.
	*/
	const_reference
	front() const;

	/**
	\brief Returns a reference to the last element of the vector.
	*/
	reference
	back();

	/**
	\brief Returns a reference to the last element of the vector.
	*/
	const_reference
	back() const;

	/**
	\brief Returns the pointer to the store.

	May return 0 if the vector is empty.
	\note
	This function is not found in (C++03's) <code>std::vector</code>
	*/
	pointer
	data();

	/**
	\brief Returns the pointer to the store.

	May return 0 if the vector is empty.
	\note
	This function is not found in (C++03's) <code>std::vector</code>
	*/
	const_pointer
	data() const;

	/**
	\brief Returns the pointer to the end of the store.

	Equal to <code>data() + size()</code>.
	\note
	This function is not found in (C++03's) <code>std::vector</code>
	*/
	pointer
	data_end();

	/**
	\brief Returns the pointer to the end of the store.

	Equal to <code>data() + size()</code>.
	\note
	This function is not found in (C++03's) <code>std::vector</code>
	*/
	const_pointer
	data_end() const;

	/**
	\brief Construct an empty vector using the specified allocator
	\param a The allocator
	*/
	explicit raw_vector(
		A const &a = A()
	);

	/**
	\brief Constructs an uninitialized vector
	\param sz The initial size of the vector
	\param a The allocator
	All of the elements will have indeterminate values and must be written
	before being read.
	*/
	explicit
	raw_vector(
		size_type sz,
		A const &a = A()
	);

	/**
	\brief Constructs an initialized vector
	\param sz The initial size of the vector
	\param t The value to assign to all elements in the vector
	\param a The allocator
	*/
	raw_vector(
		size_type sz,
		T const &t,
		A const &a = A()
	);

	/**
	\brief Constructs a vector from an iterator range
	\tparam In A forward iterator type
	\param beg The begining of the iterator range
	\param end One past the end of the iterator range
	\param a The allocator
	*/
	template<
		typename In
	>
	raw_vector (
		In beg,
		In end,
		A const &a = A()
	);

	raw_vector(
		std::initializer_list<
			value_type
		>,
		A const &a = A()
	);

	raw_vector (
		raw_vector const &
	);

	raw_vector (
		raw_vector &&
	)
	noexcept;

	~raw_vector();

	raw_vector &
	operator=(
		raw_vector const &
	);

	raw_vector &
	operator=(
		raw_vector &&
	)
	noexcept;

	/**
	\brief Erases a vector and copies the specified elements to the empty vector.
	\tparam In A forward iterator type
	\param beg The begining of the iterator range
	\param end One past the end of the iterator range
	*/
	template<
		typename In
	>
	void
	assign(
		In beg,
		In end
	);

	/**
	\brief Resizes a vector and copies the specified element to the new vector.
	\param n The vector's new size
	\param value The value to assign to all the elements
	*/
	void
	assign(
		size_type n,
		T const &value
	);

	/**
	\brief Add an element to the end of the vector.
	\param t The element to add
	*/
	void
	push_back(
		T const &t
	);

	/**
	\brief Deletes the element at the end of the vector.
	*/
	void
	pop_back();

	/**
	\brief Erases the elements of the vector.
	*/
	void
	clear();

	/**
	\brief Returns the number of elements in the vector.
	*/
	size_type
	size() const;

	/**
	\brief	Tests if the vector container is empty.
	*/
	bool
	empty() const;

	/**
	\brief Returns the maximum length of the vector.
	*/
	size_type
	max_size() const;

	/**
	\brief Returns the number of elements that the vector could contain without allocating more storage.
	*/
	size_type
	capacity() const;

	/**
	\brief Exchanges the elements of two vectors.
	*/
	void
	swap (
		raw_vector &
	);

	/**
	\brief The same as resize but doesn't initialize the newly created elements (if any)
	\note
	This function is not found in (C++03's) <code>std::vector</code>
	*/
	void
	resize_uninitialized(
		size_type sz
	);

	/**
	\brief Erases the elements of the vector.
	\param sz The new size
	\param value The value to assign to the new elements (if any)
	*/
	void
	resize(
		size_type sz,
		T const &value = T()
	);

	/**
	\brief Reserves a minimum length of storage for a vector object.
	\param sz The new (storage) size
	*/
	void
	reserve(
		size_type sz
	);

	/**
	\brief Returns an object to the allocator class used by a vector.
	*/
	allocator_type
	get_allocator() const;

	/**
	\brief Inserts an element into the vector at a specified position.
	\param position An iterator to the element <em>after</em> the new element
	\param t The new element
	*/
	iterator
	insert(
		iterator position,
		T const &t
	);

	/**
	\brief Inserts copies of an element into the vector at a specified position.
	\param position An iterator to the element <em>after</em> the new elements
	\param n How many copies to insert
	\param t The new element
	*/
	void
	insert(
		iterator position,
		size_type n,
		T const &t
	);

	/**
	\brief Inserts a range of elements into the vector at a specified position.
	\tparam In A forward iterator type
	\param position An iterator to the element <em>after</em> the new elements
	\param beg The begining of the iterator range
	\param end One past the end of the iterator range
	*/
	template<
		typename In
	>
	void
	insert(
		iterator position,
		In beg,
		In end
	);

	/**
	\brief Erases the element given by the iterator
	\param position The iterator to the element to delete
	\returns An iterator pointing to the element next to the deleted one
	*/
	iterator
	erase(
		iterator position
	);

	/**
	\brief Erase a range of elements from the vector
	\param first The begining of the iterator range
	\param last One past the end of the iterator range
	\returns An iterator pointing to the element previously located at position \p end
	*/
	iterator
	erase(
		iterator first,
		iterator last
	);

	/**
	\brief Tries to shrink capacity() to fit size()
	\note
	This function is not found in (C++03's) <code>std::vector</code>
	*/
	void
	shrink_to_fit();

	/**
	\brief Destroy this vector completely, it will then have empty storage
	Equivalent to <code>resize(0); shrink_to_fit();</code>
	\note
	This function is not found in (C++03's) <code>std::vector</code>
	*/
	void
	free_memory();
private:
// Without this, doxygen shows the "impl" data type, which is confusing
/// \cond
	template<
		typename In
	>
	typename std::enable_if<
		fcppt::type_traits::is_input_iterator<
			In
		>::value,
		void
	>::type
	insert_impl(
		iterator position,
		In begin,
		In end
	);

	template<
		typename In
	>
	typename std::enable_if<
		!fcppt::type_traits::is_input_iterator<
			In
		>::value,
		void
	>::type
	insert_impl(
		iterator position,
		In begin,
		In end
	);

	void
	range_check(
		size_type n
	) const;

	size_type
	new_capacity(
		size_type new_size
	) const;

	void
	reallocate(
		size_type new_cap
	);

	void
	set_pointers(
		pointer src,
		size_type sz,
		size_type cap
	);

	void
	deallocate();

	class impl
	{
		FCPPT_NONCOPYABLE(
			impl
		);
	public:
		explicit
		impl(
			A const &
		);

		impl(
			impl &&
		);

		impl(
			A const &,
			size_type
		);

		impl &
		operator=(
			impl &&
		);

		~impl();

		void
		reset_pointers();

		A alloc_;

		pointer
			first_,
	        	last_,
			cap_;
	};

	impl impl_;
/// \endcond
};

/**
\brief Tests two vectors for component-wise equality
*/
template<
	typename T,
	typename A
>
bool
operator==(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

/**
\brief Compares two vectors component-wise
*/
template<
	typename T,
	typename A
>
bool
operator<(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

/**
\brief Tests two vectors for component-wise inequality
*/
template<
	typename T,
	typename A
>
bool
operator!=(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

/**
\brief Compares two vectors component-wise
*/
template<
	typename T,
	typename A
>
bool
operator>(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

/**
\brief Compares two vectors component-wise
*/
template<
	typename T,
	typename A
>
bool
operator>=(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

/**
\brief Compares two vectors component-wise
*/
template<
	typename T,
	typename A
>
bool
operator<=(
	raw_vector<T, A> const &,
	raw_vector<T, A> const &
);

/**
\brief Exchanges the elements of two vectors.
*/
template<
	typename T,
	typename A
>
void
swap(
	raw_vector<T, A> &,
	raw_vector<T, A> &
);

}
}

#endif
