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

/// Checks if spheres @a a and @a b intersect
template<
	typename T,
	size_type N
>
bool
intersects(
	object<T, N> const &a,
	object<T, N> const &b
)
{
	return
		fcppt::math::vector::length(a.origin() - b.origin())
		< a.radius() + b.radius();
}

}
}
}

#endif
