//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/container/raw_vector_decl.hpp>
#include <fcppt/container/grid/dim_fwd.hpp>
#include <fcppt/container/grid/object_fwd.hpp>
#include <fcppt/container/grid/pos_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief A simple n dimensional array
\ingroup fcpptcontainergrid

See the \link fcpptcontainergrid module description \endlink for more information.
*/
template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
class object
{
// \cond  FCPPT_DOXYGEN_DEBUG
	static_assert(
		N >= 1u,
		"The dimensions of a grid cannot be zero"
	);

	typedef
	typename
	std::conditional<
		std::is_pod<
			T
		>::value,
		fcppt::container::raw_vector<
			T,
			A
		>,
		std::vector<
			T,
			A
		>
	>::type
	container;
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
	\brief A type representing the dimension of the grid
	*/
	typedef fcppt::container::grid::dim<
		size_type,
		N
	> dim;

	/**
	\brief A type representing a position in the grid
	*/
	typedef fcppt::container::grid::pos<
		size_type,
		N
	> pos;

	/**
	\brief A signed version of pos
	*/
	typedef fcppt::container::grid::pos<
		difference_type,
		N
	> signed_pos;

	/**
	\brief An empty grid.
	*/
	object();

	/**
	\brief The grid will have an initial size but the elements might not be initialized
	\param d The initial size of the grid
	*/
	explicit
	object(
		dim const &d
	);

	/**
	\brief Initialize the grid to a size and fill every cell with the same value
	\param d The size of the grid
	\param r The value to assign to each element of the grid
	*/
	object(
		dim const &d,
		const_reference r
	);

	/**
	\brief Constructs a grid from an iterator range
	\tparam In forward iterator type
	\param d The size of the grid
	\param beg The begining of the iterator range
	\param end One past the end of the iterator range
	*/
	template<
		typename In
	>
	object(
		dim const &d,
		In beg,
		In end
	);

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

	/**
	\brief Returns a reference to the grid element at a specified position.
	*/
	reference
	operator[](
		pos const &
	);

	/**
	\brief Returns a reference to the grid element at a specified position.
	*/
	const_reference
	operator[](
		pos const &
	) const;

	/**
	\brief Returns a reference to the element at a specified location in the vector.
	\throws fcppt::container::out_of_range
	*/
	reference
	at(
		pos const &
	);

	/**
	\brief Returns a reference to the element at a specified location in the grid.
	\throws fcppt::container::out_of_range
	*/
	const_reference
	at(
		pos const &
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
	\brief Resizes the grid leaving its internal elements in an unspecific
	state
	\param d The new dimensions of the grid
	\param v The value to initialize new elements with
	*/
	void
	resize_init(
		dim const &d,
		T const &v
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
