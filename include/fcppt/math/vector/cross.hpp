//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_CROSS_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_CROSS_HPP_INCLUDED

#include <fcppt/math/detail/has_size.hpp>
#include <fcppt/math/vector/normal_storage.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculates the cross product of two three-dimensional vectors
\ingroup fcpptmathvector
\tparam T The vector's <code>value_type</code>
\tparam N The vector's dimension type (must be three-dimensional if it's a static vector).
\tparam S1 The first vector's storage type
\tparam S2 The first vector's storage type

The cross product is defined here:

http://en.wikipedia.org/wiki/Cross_product
*/
template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
typename boost::enable_if<
	math::detail::has_size<
		N,
		3
	>,
	object<
		T,
		N,
		typename normal_storage<
			T,
			N
		>::type
	> const
>::type
cross(
	object<T, N, S1> const &l,
	object<T, N, S2> const &r
)
{
	return
		object<
			T,
			N,
			typename normal_storage<
				T,
				N
			>::type
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
