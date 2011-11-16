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
 * \defgroup fcpptcontainergrid fcppt::container::grid
 * \ingroup fcpptcontainer
 */

/**
\brief A simple n dimensional array
\ingroup fcpptcontainergrid

\section grid_introduction Introduction

fcppt::container::grid::object is a simple multi dimensional array similar to
<a href="http://www.boost.org/doc/libs/1_48_0/libs/multi_array/doc/index.html">boost::multi_array</a>.
Let's first take a look at how to use a simple three dimensional grid of ints.

\snippet container/grid.cpp grid_simple

Grid uses fcppt::math::dim::basic to specify its size and to obtain an element.

\warning
Grid tries to be as efficient as possible and won't necessarily initialize its elements.

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
// \cond
	BOOST_STATIC_ASSERT(
		N >= 1u
	);
// \endcond
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
public:
	typedef A allocator_type;

	typedef T value_type;

	typedef typename A::size_type size_type;

	typedef typename A::difference_type difference_type;

	typedef typename A::reference reference;

	typedef typename A::const_reference const_reference;

	typedef typename A::pointer pointer;

	typedef typename A::const_pointer const_pointer;

	typedef typename container::iterator iterator;

	typedef typename container::const_iterator const_iterator;

	typedef typename container::reverse_iterator reverse_iterator;

	typedef typename container::const_reverse_iterator const_reverse_iterator;

	typedef typename grid::dim<
		size_type,
		N
	>::type dim;

	/// An empty grid.
	object();

	/// The grid will have an initial size but the elements might not be initialized
	explicit object(
		dim const &
	);

	/// Initialize the grid to a size and fill every cell with the same value
	explicit object(
		dim const &,
		const_reference
	);

	template<
		typename In
	>
	explicit object(
		dim const &,
		In begin,
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

	reference
	operator[](
		dim const &
	);

	const_reference
	operator[](
		dim const &
	) const;

	reference
	at(
		dim const &
	);

	const_reference
	at(
		dim const &
	) const;

	dim const &
	size() const;

	size_type
	content() const;

	bool
	empty() const;

	/// Resizes the grid leaving its internal elements in an unspecific state
	void
	resize(
		dim const &
	);

	void
	shrink_to_fit();

	pointer
	data();

	const_pointer
	data() const;

	pointer
	data_end();

	const_pointer
	data_end() const;

	iterator
	begin();

	const_iterator
	begin() const;

	const_iterator
	cbegin() const;

	iterator
	end();

	const_iterator
	end() const;

	const_iterator
	cend() const;

	reverse_iterator
	rbegin();

	const_reverse_iterator
	rbegin() const;

	const_reverse_iterator
	crbegin() const;

	reverse_iterator
	rend();

	const_reverse_iterator
	rend() const;

	const_reverse_iterator
	crend() const;

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
