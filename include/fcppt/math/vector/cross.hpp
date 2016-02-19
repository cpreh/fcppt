//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_CROSS_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_CROSS_HPP_INCLUDED

#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculates the cross product of two three-dimensional vectors

\ingroup fcpptmathvector

The cross product is defined here:

http://en.wikipedia.org/wiki/Cross_product
*/
template<
	typename T,
	typename S1,
	typename S2
>
fcppt::math::vector::static_<
	T,
	3
>
cross(
	fcppt::math::vector::object<
		T,
		3,
		S1
	> const &l,
	fcppt::math::vector::object<
		T,
		3,
		S2
	> const &r
)
{
	return
		fcppt::math::vector::static_<
			T,
			3
		>(
			l.y() * r.z() - l.z() * r.y(),
			l.z() * r.x() - l.x() * r.z(),
			l.x() * r.y() - l.y() * r.x()
		);
}

}
}
}

#endif
