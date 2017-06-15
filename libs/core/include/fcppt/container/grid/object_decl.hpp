//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OBJECT_DECL_HPP_INCLUDED

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
// \cond
	static_assert(
		N >= 1u,
		"The dimensions of a grid cannot be zero"
	);

	typedef
	std::vector<
		T,
		A
	>
	container;
// \endcond
public:
	typedef
	std::integral_constant<
		fcppt::container::grid::size_type,
		N
	>
	static_size;

	typedef
	A
	allocator_type;

	typedef
	T
	value_type;

	typedef
	typename
	container::size_type
	size_type;

	typedef
	typename
	container::difference_type
	difference_type;

	typedef
	typename
	container::reference
	reference;

	typedef
	typename
	container::const_reference
	const_reference;

	typedef
	typename
	container::iterator
	iterator;

	typedef
	typename
	container::const_iterator
	const_iterator;

	/**
	\brief A type representing the dimension of the grid
	*/
	typedef
	fcppt::container::grid::dim<
		size_type,
		N
	>
	dim;

	/**
	\brief A type representing a position in the grid
	*/
	typedef
	fcppt::container::grid::pos<
		size_type,
		N
	>
	pos;

	/**
	\brief A signed version of pos
	*/
	typedef
	fcppt::container::grid::pos<
		difference_type,
		N
	>
	signed_pos;

	/**
	\brief An empty grid.
	*/
	object();

	/**
	\brief Initialize the grid to a size and fill every cell with the same value
	\param d The size of the grid
	\param r The value to assign to each element of the grid
	*/
	object(
		dim const &d,
		value_type const &r
	);

	/**
	\brief Initialize the grid by calling a function for every element

	Calls \a function for every position in the grid.

	\tparam Function A function of type <code>value_type (pos)</code>
	*/
	template<
		typename Function
	>
	object(
		dim const &size,
		Function const &function
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

	iterator
	begin();

	iterator
	end();

	const_iterator
	begin() const;

	const_iterator
	end() const;

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
	fcppt::container::grid::size_type N,
	typename A
>
void
swap(
	fcppt::container::grid::object<
		T,
		N,
		A
	> &,
	fcppt::container::grid::object<
		T,
		N,
		A
	> &
);

}
}
}

#endif
