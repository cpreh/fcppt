//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_BOX_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/box/object_fwd.hpp>
#include <fcppt/math/dim/static_fwd.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief A class representing axis aligned boxes, cubes, hypercubes, ...

\tparam T The box's <code>value_type</code>

\tparam N The box's (numeric) dimension

\ingroup fcpptmathbox

See the \link fcpptmathvector module documentation \endlink for more information.
*/
template<
	typename T,
	fcppt::math::size_type N
>
class object
{
public:
	/**
	\brief A type that represents the data type stored in a box's vector/dimension.
	*/
	typedef
	T
	value_type;

	typedef
	fcppt::math::static_size<
		N
	>
	dim_wrapper;

	/**
	\brief A type that represents the data type stored in a box's
	vector/dimension (synonymous to value_type).
	*/
	typedef
	value_type
	scalar;

	/**
	\brief A type that counts the number of elements in a box's
	vector/dimension.
	*/
	typedef
	fcppt::math::size_type
	size_type;

	/**
	\brief A type represents a box's position.
	*/
	typedef
	fcppt::math::vector::static_<
		T,
		N
	>
	vector;

	/**
	\brief A type represents a box's size.
	*/
	typedef
	fcppt::math::dim::static_<
		T,
		N
	>
	dim;

	/**
	\brief Construct an uninitialized box

	\warning
	The content of the box will be undefined (not null) after
	initialization
	*/
	explicit
	object(
		fcppt::no_init const &
	);

	/**
	\brief Construct a box from position and size

	\param pos The box's position

	\param size The box's size
	*/
	object(
		vector const &pos,
		dim const &size
	);

	/**
	\brief Construct a box from position and size

	\param min The box's min position

	\param max The box's max position
	*/
	object(
		vector const &min,
		vector const &max
	);

	/**
	\brief Return the box's position
	*/
	vector &
	pos();

	vector const &
	pos() const;

	vector &
	max();

	vector const &
	max() const;

	dim
	size() const;

	value_type
	left() const;

	value_type
	right() const;

	value_type
	top() const;

	value_type
	bottom() const;

	value_type
	front() const;

	value_type
	back() const;
private:
	vector min_;

	vector max_;
};

}
}
}

#endif
