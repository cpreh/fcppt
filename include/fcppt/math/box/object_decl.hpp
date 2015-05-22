//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_MATH_BOX_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_fwd.hpp>
#include <fcppt/math/dim/object_decl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/vector/object_decl.hpp>
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
	typedef T value_type;

	/**
	\brief A type that represents the data type stored in a box's vector/dimension (synonymous to value_type).
	*/
	typedef value_type scalar;

	/**
	\brief A type that counts the number of elements in a box's vector/dimension.
	*/
	typedef fcppt::math::size_type size_type;

	/**
	\brief A type represents a box's position.
	*/
	typedef fcppt::math::vector::static_<
		T,
		N
	> vector;

	/**
	\brief A type represents a box's size.
	*/
	typedef fcppt::math::dim::static_<
		T,
		N
	> dim;

	/**
	\brief Calls the default constructor for every element
	*/
	object();

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
	\brief Fully construct an box
	\param v The box's position
	\param s The box's size
	*/
	object(
		vector const &v,
		dim const &s
	);

	/**
	\brief Return a box at the origin with no exents
	*/
	static
	object const
	null();

	/**
	\brief Return the box's area (or volume or "content", generally speaking)
	*/
	value_type
	content() const;

	/**
	\brief Return the box's width
	*/
	value_type
	w() const;

	/**
	\brief Return the box's height
	*/
	value_type
	h() const;

	/**
	\brief Return the box's depth (if available)
	*/
	value_type
	d() const;

	/**
	\brief Return the box's position
	*/
	vector const
	pos() const;

	/**
	\brief Return the box's position incremented by it's size

	In a 2D graphics coordinate system, where the position would denote the
	"top left" of the box, this would denote the "bottom right". Box,
	however, doesn't impose any coordinate system.
	*/
	vector const
	max() const;

	/**
	\brief Return the box's size
	*/
	dim const
	size() const;

	/**
	\brief Get a component of the box's position
	\param s The component to extract from the position
	*/
	value_type
	pos(
		size_type s
	) const;

	/**
	\brief Get a component of the box's "max position" (see fcppt::math::box::max())
	\param s The component to extract from the max position
	*/
	value_type
	max(
		size_type s
	) const;

	/**
	\brief Get a component of the box's size
	\param s The component to extract from the size
	*/
	value_type
	size(
		size_type s
	) const;

	/**
	\brief Get the x coordinate of the box's position
	*/
	value_type
	left() const;

	/**
	\brief Get the y coordinate of the box's position
	*/
	value_type
	top() const;

	/**
	\brief Get the z coordinate of the box's position
	*/
	value_type
	front() const;

	/**
	\brief Get the x coordinate of the box's "max position"
	*/
	value_type
	right() const;

	/**
	\brief Get the y coordinate of the box's "max position"
	*/
	value_type
	bottom() const;

	/**
	\brief Get the z coordinate of the box's "max position"
	*/
	value_type
	back() const;

	/**
	\brief Set the x coordinate of the box's size
	*/
	void
	w(
		value_type
	);

	/**
	\brief Set the y coordinate of the box's size
	*/
	void
	h(
		value_type
	);

	/**
	\brief Set the z coordinate of the box's size
	*/
	void
	d(
		value_type
	);

	/**
	\brief Set the box's position
	*/
	void
	pos(
		vector const &
	);

	/**
	\brief Set the box's size
	*/
	void
	size(
		dim const &
	);

	/**
	\brief Set one coordinate of the box's position
	*/
	void
	pos(
		size_type index,
		value_type
	);

	/**
	\brief Set one coordinate of the box's size
	*/
	void
	size(
		size_type index,
		value_type
	);

	/**
	\brief Set the x coordinate of the box's position
	*/
	void
	left(
		value_type
	);

	/**
	\brief Set the y coordinate of the box's position
	*/
	void
	top(
		value_type
	);

	/**
	\brief Set the z coordinate of the box's position
	*/
	void
	front(
		value_type
	);

	/**
	\brief Swap the box's representation with another box
	*/
	void
	swap(
		object &
	);
private:
	vector pos_;

	dim size_;
};

/**
\brief Swap the box's representation with another box
*/
template<
	typename T,
	fcppt::math::size_type N
>
void
swap(
	fcppt::math::box::object<
		T,
		N
	> &,
	fcppt::math::box::object<
		T,
		N
	> &
);

}
}
}

#endif
