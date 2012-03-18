//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ATAN2_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ATAN2_HPP_INCLUDED

#include <fcppt/math/detail/has_size.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Computes <code>atan2(y,x)</code>
\ingroup fcpptmathvector
\tparam T The vector's <code>value_type</code>. Must be a floating point type.
\tparam N The vector's dimension type. Must be 2.
\tparam S The vector's storage type

The standard C++ function <code>std::%atan2</code>, defined in
<code>cmath</code>, has the signature:

<pre>
float atan2(float y,float x)
double atan2(double y,double x)
long double atan2(long double y,long double x)
</pre>

This function can be expressed more intuitively as taking a vector (of a
floating point type), since you don't have to remember to pass in (y,x) instead
of (x,y). This is what happens in fcppt's atan2 function.
*/
template<
	typename T,
	typename N,
	typename S
>
inline
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_floating_point<
			T
		>,
		math::detail::has_size<
			N,
			2
		>
	>,
	T
>::type
atan2(
	object<T, N, S> const &_vector
)
{
	return
		std::atan2(
			_vector.y(),
			_vector.x()
		);
}

}
}
}

#endif
