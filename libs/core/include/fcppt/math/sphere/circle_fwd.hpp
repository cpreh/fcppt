//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_SPHERE_CIRCLE_FWD_HPP_INCLUDED
#define FCPPT_MATH_SPHERE_CIRCLE_FWD_HPP_INCLUDED

#include <fcppt/math/sphere/object_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace sphere
{

/**
\brief Typedefs a sphere with a dimension of 2 (a circle)

\ingroup fcpptmathsphere
*/
template<
	typename T
>
using circle
=
fcppt::math::sphere::object<
	T,
	2
>;

}
}
}

#endif
