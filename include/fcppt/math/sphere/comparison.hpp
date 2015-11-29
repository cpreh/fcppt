//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_SPHERE_COMPARISON_HPP_INCLUDED
#define FCPPT_MATH_SPHERE_COMPARISON_HPP_INCLUDED

#include <fcppt/math/sphere/object_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>


namespace fcppt
{
namespace math
{
namespace sphere
{

/**
\brief Compares two spheres for equality

\ingroup fcpptmathsphere
*/
template<
	typename T,
	fcppt::math::size_type N
>
bool
operator==(
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
		_a.origin()
		==
		_b.origin()
		&&
		_a.radius()
		==
		_b.radius();
}

/**
\brief Compares two spheres for inequality

\ingroup fcpptmathsphere
*/
template<
	typename T,
	fcppt::math::size_type N
>
bool
operator!=(
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
		!(_a == _b);
}

}
}
}

#endif
