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
#include <fcppt/math/dim/static.hpp>
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
	\brief Fully construct an box

	\param v The box's position

	\param s The box's size
	*/
	object(
		vector const &v,
		dim const &s
	);

	/**
	\brief Return the box's position
	*/
	vector &
	pos();

	/**
	\brief Return the box's position
	*/
	vector const &
	pos() const;

	/**
	\brief Return the box's position plus its size

	In a 2D graphics coordinate system, where the position would denote the
	"top left" of the box, this would denote the "bottom right". Box,
	however, doesn't impose any coordinate system.
	*/
	vector
	max() const;

	/**
	\brief Return the box's size
	*/
	dim &
	size();

	/**
	\brief Return the box's size
	*/
	dim const &
	size() const;

	/**
	\brief Get a component of the box's "max position" (see fcppt::math::box::max())
	\param s The component to extract from the max position
	*/
	value_type
	max(
		size_type s
	) const;

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
private:
	vector pos_;

	dim size_;
};

}
}
}

#endif
