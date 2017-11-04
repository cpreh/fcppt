//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ATAN2_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ATAN2_HPP_INCLUDED

#include <fcppt/math/is_zero.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Computes atan2 of a vector.

\ingroup fcpptmathvector

Computes <code>atan2(_vector.y(),_vector.x())</code>. In case
x or y is zero, nothing is returned.

The standard C++ functions <code>std::%atan2</code>, defined in
<code>cmath</code>, have the signature:

<pre>
float atan2(float y,float x)
double atan2(double y,double x)
long double atan2(long double y,long double x)
</pre>

These functions can be expressed more intuitively as taking a vector (of a
floating-point type), since you don't have to remember to pass in (y,x) instead
of (x,y). This is what happens in fcppt's atan2 function.

\tparam T Must be a floating-point type.
*/
template<
	typename T,
	typename S
>
inline
fcppt::optional::object<
	T
>
atan2(
	fcppt::math::vector::object<
		T,
		2,
		S
	> const &_vector
)
{
	static_assert(
		std::is_floating_point<
			T
		>::value,
		"atan2 can only be used on vectors of floating point type"
	);

	return
		fcppt::optional::make_if(
			!(
				fcppt::math::is_zero(
					_vector.x()
				)
				||
				fcppt::math::is_zero(
					_vector.y()
				)
			),
			[
				&_vector
			]{
				return
					std::atan2(
						_vector.y(),
						_vector.x()
					);
			}
		);
}

}
}
}

#endif
