//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_DECL_HPP_INCLUDED

#include <fcppt/container/array_fwd.hpp>
#include <fcppt/container/detail/array_storage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <cstddef>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief An implementation of <code>std::array</code> (see <a href="http://en.wikipedia.org/wiki/Array_(C%2B%2B)">here</a> for a reference)
\tparam T The type of an element.
\tparam N The number of elements.
\ingroup fcpptcontainer

\section Motivation

If you want to create an array whose size is fixed at compile-time, you have a
range of options. Each option, however, has drawbacks. Here's a non-exhaustive
list of options:

<table>
<tr>
<th>Option</th>
<th>Description</th>
</tr>
<tr>
<td><code>std::array</code></td>
<td>
<ul>
	<li>Future-proof, since it's in the next C++ standard (C++11)</li>
	<li>Supported by all major compilers</li>
	<li>Clean interface</li>
	<li>Needs C++11 support enabled for your project</li>
</ul>
</td>
</tr>
<tr>
<td><code>std::tr1::array</code></td>
<td>
<ul>
	<li>Clean interface</li>
	<li>Needs tr1-compatibility</li>
	<li>Isn't well supported (gcc's tr1 implementation is frozen)</li>
</ul>
</td>
</tr>
<tr>
<td><code>boost::array</code></td>
<td>
<ul>
	<li>Needs boost</li>
	<li>Old code (support for older compilers, meaning lots of ugly macros in the code)</li>
	<li>Does out-of-bounds checks even with <code>operator[]</code> (inside a <code>BOOST_ASSERT</code>, but still unnecessary)</li>
</ul>
</td>
</tr>
</table>

fcppt::container::array is a clean (macro-free) implementation of
<code>std::%array</code> without out-of-bounds checks in
<code>operator[]</code>.
*/
template<
	typename T,
	std::size_t N
>
struct array
{
	/**
	\brief A type that provides a reference to an element stored in an array.
	*/
	typedef T &reference;

	/**
	\brief A type that provides a reference to a <code>const</code> element stored in an array for reading and performing <code>const</code> operations.
	*/
	typedef T const &const_reference;

	/**
	\brief A type that provides a random-access iterator that can read or modify any element in an array.
	*/
	typedef T *iterator;

	/**
	\brief A type that provides a random-access iterator that can read a <code>const</code> element in an array.
	*/
	typedef T const *const_iterator;

	/**
	\brief A type that counts the number of elements in an array.
	*/
	typedef std::size_t size_type;

	/**
	\brief A type that provides the difference between the addresses of two elements in an array.
	*/
	typedef std::ptrdiff_t difference_type;

	/**
	\brief A type that represents the data type stored in an array.
	*/
	typedef T value_type;

	/**
	\brief A type that provides a pointer to an element in an array.
	*/
	typedef T *pointer;

	/**
	\brief A type that provides a pointer to a <code>const</code> element in an array.
	*/
	typedef T const *const_pointer;

	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a reversed array.
	*/
	typedef std::reverse_iterator<iterator> reverse_iterator;

	/**
	\brief A type that provides a random-access iterator that can read any <code>const</code> element in the array.
	*/
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	/**
	\brief This is for boost::array compatibility
	*/
	static size_type const static_size = N;

	/**
	\brief The static size as an mpl::integral_c
	*/
	typedef boost::mpl::integral_c<
		size_type,
		N
	> dim_wrapper;

	/// \cond
	typename detail::array_storage<
		T,
		N
	>::type elem_;
	/// \endcond

	/**
	\brief Replaces all elements with a specified value.
	\param v The value to assign to each array element

	I accidentally the whole array!
	*/
	void
	fill(
		T const &v
	);

	/**
	\brief Swaps the elements with the other array
	\param v A different array of the same size

	This takes linear time and may throw.
	*/
	void
	swap(
		array<T, N> &v
	);

	/**
	\brief Returns a random-access iterator to the first element in the array.
	*/
	iterator
	begin();

	/**
	\brief Returns a random-access const iterator to the first element in the array.
	*/
	const_iterator
	begin() const;

	/**
	\brief Returns a random-access iterator that points just beyond the end of the array.
	*/
	iterator
	end();

	/**
	\brief Returns a random-access const iterator that points just beyond the end of the array.
	*/
	const_iterator
	end() const;

	/**
	\brief Returns an iterator to the first element in a reversed array.
	*/
	reverse_iterator
	rbegin();

	/**
	\brief Returns a const iterator to the first element in a reversed array.
	*/
	const_reverse_iterator
	rbegin() const;

	/**
	\brief Returns an iterator to the end of a reversed array.
	*/
	reverse_iterator
	rend();

	/**
	\brief Returns a const iterator to the end of a reversed array.
	*/
	const_reverse_iterator
	rend() const;

	/**
	\brief Returns a random-access const iterator to the first element in the array.
	*/
	const_iterator
	cbegin() const;

	/**
	\brief Returns a random-access iterator that points just beyond the end of the array.
	*/
	const_iterator
	cend() const;

	/**
	\brief Returns a const iterator to the first element in a reversed array.
	*/
	const_reverse_iterator
	crbegin() const;

	/**
	\brief Returns a const iterator to the end of a reversed array.
	*/
	const_reverse_iterator
	crend() const;

	/**
	\brief Counts the number of elements.
	*/
	size_type
	size() const;

	/**
	\brief Counts the number of elements.
	*/
	size_type
	max_size() const;

	/**
	\brief Tests whether elements are present.

	The member function returns true only if \p N == 0.
	*/
	bool
	empty() const;

	/**
	\brief Accesses an element at a specified position.
	\param i The desired position
	*/
	reference
	operator[](
		size_type i
	);

	/**
	\brief Accesses an element at a specified position.
	\param i The desired position
	*/
	const_reference
	operator[](
		size_type i
	) const;

	/**
	\brief Accesses an element at a specified position.
	\param i The desired position
	\throws fcppt::container::out_of_range If \p i is out of range
	*/
	reference
	at(
		size_type i
	);

	/**
	\brief Accesses an element at a specified position.
	\param i The desired position
	\throws fcppt::container::out_of_range If \p i is out of range
	*/
	const_reference
	at(
		size_type i
	) const;

	/**
	\brief Accesses the first element.
	*/
	reference
	front();

	/**
	\brief Accesses the first element.
	*/
	const_reference
	front() const;

	/**
	\brief Accesses the last element.
	*/
	reference
	back();

	/**
	\brief Accesses the last element.
	*/
	const_reference
	back() const;

	/**
	\brief Gets the address of the first element.
	*/
	pointer
	data();

	/**
	\brief Gets the address of the first element.
	*/
	const_pointer
	data() const;

	/**
	\brief Gets the address of one element behind the last element
	\note
	This is not included in C++11s' <code>std::%array</code>
	*/
	pointer
	data_end();

	/**
	\brief Gets the address of one element behind the last element
	\note
	This is not included in C++11s' <code>std::%array</code>
	*/
	const_pointer
	data_end() const;
};

}
}

#endif
