//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_SPHERE_INTERSECTS_HPP_INCLUDED
#define FCPPT_MATH_SPHERE_INTERSECTS_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/sphere/object_fwd.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace sphere
{

/**
\brief Checks if two spheres intersect

\ingroup fcpptmathsphere
*/
template<
	typename T,
	fcppt::math::size_type N
>
bool
intersects(
	fcppt::math::sphere::object<
		T,
		N
	> const &_a,
	fcppt::math::sphere::object<
		T,
		N
	> const &_b
)
{
	return
		fcppt::math::vector::length(
			_a.origin()
			-
			_b.origin()
		)
		<
		_a.radius()
		+
		_b.radius();
}

}
}
}

#endif
