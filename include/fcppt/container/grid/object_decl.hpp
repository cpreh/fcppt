//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/container/raw_vector_decl.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/object_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/basic_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_pod.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
/// Contains fcppt::container:grid::object and helper types/functions for it.
namespace grid
{

/**
\defgroup fcpptcontainergrid fcppt::container::grid
\ingroup fcpptcontainer
\brief See the documentation for fcppt::container::grid::object for more information.
*/

/**
\brief A simple n dimensional array
\ingroup fcpptcontainergrid

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref grid_introduction</li>
	<li>\ref grid_iteration</li>
	<li>\ref grid_resizing</li>
</ol>

</td>
</tr>
</table>

\section grid_introduction Introduction

fcppt::container::grid::object is a simple multi dimensional array similar to
<a href="http://www.boost.org/doc/libs/1_48_0/libs/multi_array/doc/index.html">boost::multi_array</a>.
Let's first take a look at how to use a simple three dimensional grid of ints.

\snippet container/grid.cpp grid_simple

Grid uses fcppt::math::dim::basic to specify its size and to obtain an element.

\warning
Grid tries to be as efficient as possible and won't necessarily initialize its elements.

\section grid_iteration Iteration

Internally, the grid uses a <code>std::vector</code> or a
fcppt::container::raw_vector to linearly represent the grid. The iterators
returned by the grid are iterators over that internal storage array, so they're
not special in any way (other than begin random-access). This also means that iteration is...
<ul>
<li>
...<em>linear</em> for <em>one-dimensional</em> grids (from left to right)
</li>
<li>
...<em>row-major</em> for <em>two-dimensional</em> grids; this means that
iteration begins at the top left with row 0, proceeds to the top right, then
goes to the right of row 2 and so on.

\image html grid_row_major.svg "Row-major iteration"
</li>
<li>
...<em>vertical-slice-major</em> for <em>three-dimensional</em> grids; this
means that iteration starts at the top left back (z=0) of the cube, then
iterates over all elements with z equal to zero, then starts at the top left
back (z=1) of the cube, and so on.
</li>
<li>...and so on in higher dimensions</li>
</ul>

Here is an example of each iteration method:

\snippet container/grid.cpp grid_iteration

To get the position of an iterator, use fcppt::container::grid::iterator_position.

\section grid_resizing Resizing

To resize a grid there are a couple of options. \link
fcppt::container::grid::object::resize resize \endlink will resize the
underlying container but leave the elements of the grid in an unspecific state.

There are two functions to preserve the current elements that will still fit
into the grid after the resize: \link fcppt::container::grid::resize_preserve
resize_preserve \endlink and \link fcppt::container::grid::resize_preserve_init
resize_preserve_init \endlink.

<code>resize_preserve</code> only preserves the elements that still fit but
doesn't initialize new elements.  <code>resize_preserve_init</code> is like
<code>resize_preserve</code> but will give all new elements a default value.

Here's an example:

\snippet container/grid.cpp grid_resize
*/
template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
class object
{
// \cond  FCPPT_DOXYGEN_DEBUG
	BOOST_STATIC_ASSERT(
		N >= 1u
	);

	typedef typename boost::mpl::if_<
		boost::is_pod<
			T
		>,
		fcppt::container::raw_vector<
			T,
			A
		>,
		std::vector<
			T,
			A
		>
	>::type container;
// \endcond
public:
	/**
	\brief A type that represents the allocator class for the grid's storage.
	*/
	typedef A allocator_type;

	/**
	\brief A type that represents the data type stored in a grid.
	*/
	typedef T value_type;

	/**
	\brief A type that counts the number of elements in a grid.
	*/
	typedef typename A::size_type size_type;

	/**
	\brief A type that provides the difference between the addresses of two elements in a grid.
	*/
	typedef typename A::difference_type difference_type;

	/**
	\brief A type that provides a reference to an element stored in a grid.
	*/
	typedef typename A::reference reference;

	/**
	\brief A type that provides a reference to a <code>const</code> element stored in a grid for reading and performing <code>const</code> operations.
	*/
	typedef typename A::const_reference const_reference;

	/**
	\brief A type that provides a pointer to an element in a grid.
	*/
	typedef typename A::pointer pointer;

	/**
	\brief A type that provides a pointer to a <code>const</code> element in a grid.
	*/
	typedef typename A::const_pointer const_pointer;

	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a grid.
	*/
	typedef typename container::iterator iterator;

	/**
	\brief A type that provides a random-access iterator that can read a <code>const</code> element in a grid.
	*/
	typedef typename container::const_iterator const_iterator;

	/**
	\brief A type that provides a random-access iterator that can read or modify any element in a reversed grid.
	*/
	typedef typename container::reverse_iterator reverse_iterator;

	/**
	\brief A type that provides a random-access iterator that can read any <code>const</code> element in the grid.
	*/
	typedef typename container::const_reverse_iterator const_reverse_iterator;

	/**
	\brief A type representing the dimension of the array
	*/
	typedef typename grid::dim<
		size_type,
		N
	>::type dim;

	/**
	\brief An empty grid.
	*/
	object();

	/**
	\brief The grid will have an initial size but the elements might not be initialized
	\param d The initial size of the grid
	*/
	explicit object(
		dim const &d
	);

	/**
	\brief Initialize the grid to a size and fill every cell with the same value
	\param d The size of the grid
	\param r The value to assign to each element of the grid
	*/
	explicit object(
		dim const &d,
		const_reference r
	);

	/**
	\brief Constructs a grid from an iterator range
	\tparam A forward iterator type
	\param d The size of the grid
	\param beg The begining of the iterator range
	\param end One past the end of the iterator range
	*/
	template<
		typename In
	>
	explicit object(
		dim const &d,
		In beg,
		In end
	);

	object(
		object const &
	);

	object &
	operator=(
		object const &
	);

	~object();

	/**
	\brief Returns a reference to the grid element at a specified position.
	*/
	reference
	operator[](
		dim const &
	);

	/**
	\brief Returns a reference to the grid element at a specified position.
	*/
	const_reference
	operator[](
		dim const &
	) const;

	/**
	\brief Returns a reference to the element at a specified location in the vector.
	\throws fcppt::container::out_of_range
	*/
	reference
	at(
		dim const &
	);

	/**
	\brief Returns a reference to the element at a specified location in the grid.
	\throws fcppt::container::out_of_range
	*/
	const_reference
	at(
		dim const &
	) const;

	/**
	\brief Returns the grid's size
	\warning
	In contrast to the standard containers, this does not return a
	<code>size_type</code> value, but the dimension. Use content() to get
	the number of elements
	*/
	dim const &
	size() const;

	/**
	\brief Returns the number of elements in the grid.
	*/
	size_type
	content() const;

	/**
	\brief Tests if the grid is empty.
	*/
	bool
	empty() const;

	/**
	\brief Resizes the grid leaving its internal elements in an unspecific state
	\param d The new dimensions of the grid
	*/
	void
	resize(
		dim const &d
	);

	/**
	\brief Tries to shrink capacity() to fit size()
	*/
	void
	shrink_to_fit();

	/**
	\brief Returns the pointer to the store.
	*/
	pointer
	data();

	/**
	\brief Returns the pointer to the store.
	*/
	const_pointer
	data() const;

	/**
	\brief Returns the pointer to the end of the store.

	Equal to <code>data() + size()</code>.
	*/
	pointer
	data_end();

	/**
	\brief Returns the pointer to the end of the store.

	Equal to <code>data() + size()</code>.
	*/
	const_pointer
	data_end() const;

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
	\brief Returns a random-access const-iterator to the first element in the container.
	*/
	const_iterator
	cbegin() const;

	/**
	\brief Returns a random-access iterator that points just beyond the end of the grid.
	*/
	iterator
	end();

	/**
	\brief Returns a random-access iterator that points just beyond the end of the grid.
	*/
	const_iterator
	end() const;

	/**
	\brief Returns a random-access const-iterator that points just beyond the end of the grid.
	*/
	const_iterator
	cend() const;

	/**
	\brief Returns an iterator to the first element in a reversed grid.
	*/
	reverse_iterator
	rbegin();

	/**
	\brief Returns an iterator to the first element in a reversed grid.
	*/
	const_reverse_iterator
	rbegin() const;

	/**
	\brief Returns a const-iterator to the first element in a reversed grid.
	*/
	const_reverse_iterator
	crbegin() const;

	/**
	\brief Returns an iterator to the end of a reversed grid.
	*/
	reverse_iterator
	rend();

	/**
	\brief Returns an iterator to the end of a reversed grid.
	*/
	const_reverse_iterator
	rend() const;

	/**
	\brief Returns an iterator to the end of a reversed grid.
	*/
	const_reverse_iterator
	crend() const;

	/**
	\brief Exchanges the elements of two grids.
	*/
	void
	swap(
		object &
	);
private:
	container container_;

	dim size_;
};

template<
	typename T,
	size_type N,
	typename A
>
void
swap(
	object<T, N, A> &,
	object<T, N, A> &
);

}
}
}

#endif
